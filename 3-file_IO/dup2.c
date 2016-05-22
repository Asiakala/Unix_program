#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char *argv)
{
	int fd;
	if((fd = open("test.txt",O_RDWR))<0)
		perror("open");
	printf("fd = %d\n",fd);

	dup2(1,0);
	dup2(fd,1);

	write(1,"hello",5);

	sleep(100);

	exit(0);
}
