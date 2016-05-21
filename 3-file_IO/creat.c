#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	
	printf("open test.txt fd is : %d\n",open("test.txt",O_RDWR));
	
	if((fd = open("/dev/fd/3",O_RDWR | O_CREAT | O_TRUNC,S_IRWXU))<0){
		perror("open");
	}

	printf("fd is %d\n",fd);
	printf("open test.txt fd is : %d\n",open("test.txt",O_RDWR));
	
	sleep(100);

	exit(0);
}
