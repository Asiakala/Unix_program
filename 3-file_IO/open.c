#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	if((fd = open("test.txt",O_RDWR | O_CREAT | O_APPEND,S_IRWXU))<0){
		perror("open");
	}

	if((write(fd,"this test!",10))!=10){
		perror("write");
	}

	printf("before exit\n");

	exit(0);
}
