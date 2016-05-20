#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 200

char buf[SIZE];

int main(int argc,char *argv[])
{
	int fd;
	int cyc=2000000;
	
	memset(buf,'B',SIZE);	

	if((fd = open("test.txt",O_WRONLY))<0){
		perror("open in write");
	}

	while(cyc--){
		printf("write\n");
		if(write(fd,buf,SIZE)!=SIZE){
			perror("write");
		}
	}
	
	exit(0);
}
