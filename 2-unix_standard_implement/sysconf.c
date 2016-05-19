#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	printf("ARG_MAX = %ld\n",sysconf(_SC_ARG_MAX));
	printf("IOV_MAX = %ld\n",sysconf(_SC_IOV_MAX));
	printf("CHILD_MAX = %ld\n",sysconf(_SC_CHILD_MAX));
	printf("CLK_TCK = %ld\n",sysconf(_SC_CLK_TCK));
	printf("OPEN_MAX = %ld\n",sysconf(_SC_OPEN_MAX));
	printf("STREAM_MAX = %ld\n",sysconf(_SC_STREAM_MAX));

	exit(0);
}
