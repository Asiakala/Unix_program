#include "apue.h"

#define SIZE 1024

static void chatattime(char *);

char stra[SIZE];
char strb[SIZE];

int main(int argc,char *argv[])
{
	pid_t pid;
	
	memset(stra,'1',SIZE-1);
	memset(strb,'2',SIZE-1);
	stra[SIZE-1]='\0';
	strb[SIZE-1]='\0';

	if((pid = fork())<0)
		perror("fork");
	else if(pid == 0){
		chatattime(stra);
	}else{
		chatattime(strb);
	}

	exit(0);
}

static void chatattime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout,NULL);
	for(ptr=str;(c = *ptr++) != '\0';){
		putc(c,stdout);
	}
}


