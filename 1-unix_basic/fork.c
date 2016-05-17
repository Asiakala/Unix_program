#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int status;
	pid_t pid;

	printf("before fork...\n\n");
	if((pid = fork())<0){
		perror("fork");
	}
	else if(pid == 0){
		printf("this is child process...\n");
		execl("./io_line_buff",(char *)0,NULL);
		perror("execl");
	}

	printf("this is father process...\n");
	printf("wait for child exit...\n");
	if((pid = waitpid(pid,&status,0))<0){
		perror("waitpid");
	}

	printf("father exit...\n");
	exit(0);
}
