#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 200

char buf[SIZE];
char bufA[SIZE];
char bufB[SIZE];

int main(int argc,char *argv[])
{
	int fd,len;

	memset(bufA,'A',SIZE-1);
	memset(bufB,'B',SIZE-1);
	bufA[SIZE] = '\0';
	bufB[SIZE] = '\0';

	if((fd = open("test.txt",O_RDONLY))<0){
		perror("open");
	}

	while((len = read(fd,buf,1))>0){
		if(buf[0]=='A'){
			if((len = read(fd,buf,SIZE-1))!=(SIZE-1)){
				printf("read %d A\n",len);
			}
			buf[SIZE-1]='\0';
			if(strcmp(buf,bufA)!=0){
				printf("not AAA...\n");
				exit(-1);
			}
		}else if(buf[0]=='B'){
			if((len = read(fd,buf,SIZE-1))!=(SIZE-1)){
				printf("read %d  B\n",len);
			}
			buf[SIZE-1]='\0';
			if(strcmp(buf,bufB)!=0){
				printf("not BBB...\n");
				exit(-1);
			}

		}
	}	
		
	exit(0);
}
