#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=unknown","PATH=/tmp",NULL};

int main(int argc,char *argv[])
{
	pid_t pid;
	
	if((pid = fork())<0)
		perror("fork");
	else if(pid == 0){
		if(execle("/home/ubuntu/Unix_program/8-process_control/argv.out","aaa","bbb","ccc",NULL,env_init) < 0)
			perror("execle");
	}

	if(waitpid(pid,NULL,0) < 0)
		perror("waitpid");

	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0){
		if(execlp("ls","..",NULL) < 0)
                        perror("execlp");
	}

	exit(0);
}
