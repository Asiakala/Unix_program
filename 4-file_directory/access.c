#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("usage: ./a.out <file>\n");
		return 0;
	}

	if(access(argv[1],R_OK) < 0)
		perror("access");
	else
		printf("read access OK!\n");
	if(open(argv[1],O_RDONLY)<0)
		perror("open");
	else
		printf("open for read OK!\n");
	
	exit(0);
}
