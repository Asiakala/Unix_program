#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024

int main(int argc,char * argv[])
{
	char buff[SIZE];
	int len,ret,c;
/*
	while((c = fgetc(stdin)) != EOF){
		if((c = fputc(c,stdout)) == EOF){
			perror("fputc");
		}
	}

	exit(0);
*/
	while((len = read(STDIN_FILENO,buff,SIZE)) > 0){
		if((ret = write(STDOUT_FILENO,buff,len))!=len){
			perror("write");
		}
	}

	exit(0);
}
