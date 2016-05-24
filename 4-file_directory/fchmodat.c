#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;

	if((fd = open("/home/ubuntu/GIT/",O_RDONLY))<0)
		perror("open");
	
	if(fchmodat(fd,"Unix_program/3-file_IO/write.out",S_IRWXU,0)<0)
		perror("fchownat");

	exit(0);
}
