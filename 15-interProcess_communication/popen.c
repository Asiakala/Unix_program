#include <apue.h>
#include <sys/wait.h>

#define MAXLINE 4096

int main(int argc,char * argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	if((fpin = popen("./myuclc.out","r")) == NULL)
		perror("popen");
	for(;;){
		fputs("prompt>",stdout);

		fflush(stdout);
		if(fgets(line,MAXLINE,fpin) == NULL)
			break;
		if(fputs(line,stdout) == EOF)
			perror("fputs");
	}
	if(pclose(fpin) == -1)
		perror("pclose");
	putchar('\n');

	exit(0);
}

