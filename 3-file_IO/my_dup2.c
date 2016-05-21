#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int my_dup2(int fd,int fd2){
	int buf[SIZE],len=0;
	int temp_fd;

	if(fd2<0 || fd2>=1024)
		return -1;

	if(fd == fd2)
		return fd2;

	close(fd2);
	
	while((temp_fd = dup(fd))!=fd2){
		buf[len++] = temp_fd;
	}

	for(;len>0;len--)
		close(buf[len-1]);

	return fd2;
}

int main(int argc,char *argv[])
{
	int fd;
	fd = my_dup2(1,1023);
	printf("fd = %d\n",fd);

	write(1,"stdout",6);
	printf("\n");
	write(fd,"dup2_fd",7);
	printf("\n");

	exit(0);
}
