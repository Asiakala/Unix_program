#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	char *p;
	int len = 0;

	printf("pid = %d\n",getpid());	
	while(1){
		if((p = (char *)malloc(1048576)) == NULL){
			perror("malloc");
			printf("len = %d\n",len);
			return -1;
		}
		
//		memset(p,'1',1048576);

		len++;
//		usleep(1000000);
	}

	sleep(100);

	exit(0);
}
