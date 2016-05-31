#include <apue.h>

int globalvar = 6;

char buf[5] = "out\n";

int main(int argc,char *argv[])
{
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n");
	if((pid = vfork()) < 0){
		perror("vfork");
	}else if(pid == 0){
		globalvar++;
		var++;
		close(STDOUT_FILENO);
		exit(0);
	}

	printf("pid = %ld, globalvar = %d, var = %d\n",(long)getpid(),globalvar,var);

	write(STDOUT_FILENO,buf,strlen(buf));	

	exit(0);
}
