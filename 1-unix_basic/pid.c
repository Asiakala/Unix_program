#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char * argv[])
{
	printf("pid = %ld\n",(long int)getpid());
	printf("ppid = %ld\n",(long int)getppid());
	exit(0);
}
