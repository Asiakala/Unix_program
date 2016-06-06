#include <apue.h>
#include <sys/select.h>

#define FD_SIZE 10

int main(int argc,char *argv[])
{
	int ret,i;
	char buf[100];
	fd_set readfds,writefds,exceptfds;
	
	FD_ZERO(&readfds);
	FD_SET(1,&readfds);

	if(FD_ISSET(1,&readfds))
		printf("in\n");
	else printf("not in\n");
	
	ret = select(FD_SIZE,&readfds,NULL,NULL,NULL);
	printf("ret = %d\n",ret);
	for(i=0;i<FD_SIZE;i++){
		if(FD_ISSET(i,&readfds)){
			ret = read(i,buf,5);
			printf("buf = %s\n",buf);
		}
	}

	exit(0);
}
