#include <apue.h>

int main(int aegc,char *argv[])
{
	pid_t pid;
	
	if((pid = fork())<0)
		perror("fork1");
	else if(pid == 0){
		printf("child 1 pid = %d\n",getpid());
		exit(0);
	}else{
		printf("parent 1 pid = %d, child pid = %d\n",getpid(),pid);
	}

	if((pid = fork())<0)
		perror("fork2");
	else if(pid == 0){
		printf("child 2 pid = %d\n",getpid());
		exit(0);
	}else{
		printf("parent 2 pid = %d, child pid = %d\n",getpid(),pid);
	}
}
