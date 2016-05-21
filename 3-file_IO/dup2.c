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

	fd = 1;

	printf("fd = %d\n",dup2(fd,0));
	printf("fd = %d\n",dup2(fd,1));
	printf("fd = %d\n",dup2(fd,2));

	exit(0);
}
