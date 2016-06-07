#include <apue.h>
#include <sys/wait.h>

#define MAXLINE 4096

int main(int argc,char * argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	if((fpin = popen("./myuclc","r")) == NULL)
		perror("popen");
	for(;;){
		fputs();
	}

	exit(0);
}

