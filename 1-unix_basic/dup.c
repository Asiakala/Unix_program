#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fp=0;

	while((fp = dup(1))>0&&fp<=100){
		printf("fp = %d ",fp);
	}
	printf("exit \n");
	
	write(99,"hello ",6);
	close(99);
	sleep(3);
	write(10,"hello ",6);
	write(101,"hello ",6);

	exit(0);
}
