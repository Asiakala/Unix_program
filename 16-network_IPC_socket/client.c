#include <apue.h>
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int domain,int type,int protocol,const struct sockaddr *addr,socklen_t alen);


int main(int argc,char *argv[]){
	
	int sockfd;

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		perror("socket");

	close(sockfd);

	exit(0);
}

int connect_retry(int domain,int type,int protocol,const struct sockaddr *addr,socklen_t alen)
{
	int numsec,fd;

	for(numsec = 1;numsec <= MAXSLEEP;numsec <<= 1){
		if((fd = socket(domain,type,protocol)) < 0){
			perror("socket");
			return(-1);
		}
		if(connect(fd,addr,alen) == 0){
			printf("connect to server success!\n");
			return (0);
		}
		close(fd);

		if(numsec <= MAXSLEEP)
			sleep(numsec);
	}

	printf("can't connect to server!\n");

	return -1;
}
