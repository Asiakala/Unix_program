#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 1024

int main(int argc,char *argv[])
{
	printf("len = %d\n",printf(""));

	char name[L_tmpnam],line[MAXLINE];
	FILE *fp;

	printf("%s\n",tmpnam(NULL));

	tmpnam(name);
	printf("name  = %s\n",name);

	if((fp = tmpfile()) == NULL)
		perror("tmpfile");
	fputs("one line of output\n",fp);
	rewind(fp);
	if(fgets(line,sizeof(line),fp) == NULL)
		perror("fgets");
	fputs(line,stdout);

	sleep(30);

	exit(0);
}
