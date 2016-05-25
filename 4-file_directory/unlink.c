#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
	if(open("tempfile",O_RDWR)<0)
		perror("open");
	if(unlink("tempfile")<0)
		perror("unlink");
	printf("file unlinked OK!\n");
	sleep(20);
	printf("done!\n");

	exit(0);
}
