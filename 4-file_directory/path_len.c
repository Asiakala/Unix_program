#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char buf[20000];

int main(int argc,char *argv[])
{
	while(mkdir("test",S_IRWXU|S_IRWXG|S_IRWXO)==0){
		if(chdir("./test/")<0){
			perror("chdir");
			exit(-1);
		}
		if(getcwd(buf,20000)==NULL){
			perror("getcwd");
			exit(-1);
		}

		printf("pathlen = %d\n",strlen(buf));
	}
	perror("mkdir");
	exit(0);
}
