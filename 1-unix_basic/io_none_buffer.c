#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char * argv[])
{
	fprintf(stderr,"this is a test!","%s");

	sleep(5);
	exit(0);
}
