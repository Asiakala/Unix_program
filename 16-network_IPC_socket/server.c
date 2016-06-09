#include <apue.h>
#include <sys/socket.h>

int initserver(int type,const struct sockaddr *addr,socklen_t alen,int qlen);

int main(int argc,char *argv[]){
	
	int sockfd;
	struct sockaddr addr;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		perror("socket");


	if((sockfd = initserver(SOCK_STREAM,)))



	close(sockfd);

	exit(0);
}

int initserver(int type,const struct sockaddr *addr,socklen_t alen,int qlen)
{
	int fd,err;
	int reuse = 1;

	if((fd = socket(addr->sa_family,type,0)) < 0){
		perror("socket");
		return (-1);
	}
	if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)) < 0)
		goto errout;
	if(bind(fd,addr,alen) < 0)
		goto errout;
	if(type == SOCK_STREAM || type == SOCK_SEQPACKET)
		if(listen(fd,qlen) < 0)
			goto errout;
	return (fd);

errout:
	err = errno;
	close(fd);
	errno = err;
	return (-1);
}
