#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

int main(int argc,char argv[])
{
	char *p1,*p2,*p3,*p4;

	if((p1 = (char *)malloc(100)) == NULL)
		perror("malloc");
	if((p2 = (char *)realloc(p1,200)) == NULL)
		perror("realloc");

	if((p3 = (char *)calloc(1,100)) == NULL)
		perror("calloc");

	if((p4 = (char *)alloca(100)) == NULL)  //do not need to free p4,because it is on stack alloced;
		perror("alloca");

	free(p2);
	free(p3);

	return 0;
}
