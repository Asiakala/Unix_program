#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd1,fd2,fd3;
	if((fd1 = open("test.txt",O_RDWR))<0){
		perror("open");
	}

	printf("fd1 is %d\n",fd1);
	
	if((fd2 = open("test.txt",O_RDWR))<0){
		perror("open");
	}

	printf("fd2 is %d\n",fd2);

	if((write(fd1,"this is fd1 write! ",19))!=19){
		perror("write1");
	}
	if((write(fd2,"this is fd2 write! ",19))!=19){
		perror("write2");
	}

	if((fd3 = dup(fd2))<0)
		perror("dup");

	if((write(fd3,"this is fd3 write! ",19))!=19){
		perror("write3");
	}

	printf("before exit\n");

	exit(0);
}
