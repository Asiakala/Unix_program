#include <apue.h>
#include <fcntl.h>
#include <errno.h>

char buf[500000];

int main(int argc,char *argv[])
{
	int 	ntowrite,nwrite;
	char 	*ptr;
	int fd_flag;

	ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
	fprintf(stderr,"read %d bytes\n",ntowrite);

	fd_flag = fcntl(STDOUT_FILENO,F_GETFL,fd_flag);
	printf("fd_flag = %d\n",fd_flag);
	fd_flag |= O_NONBLOCK;
	fd_flag = fcntl(STDOUT_FILENO,F_SETFL,fd_flag);
	printf("fd_flag = %d\n",fd_flag);

	ptr = buf;
	while(ntowrite > 0){
		errno = 0;
		nwrite = write(STDOUT_FILENO,ptr,ntowrite);
	if(nwrite != -1)fprintf(stderr,"nwrite = %d, errno = %d\n",nwrite,errno);

		if(nwrite > 0){
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
	
	exit(0);
}
