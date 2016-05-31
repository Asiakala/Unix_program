#include <apue.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	pid_t pid;

	if(setpgid(getpid(),0) < 0)
		perror("setpgid1");
	
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0){
		
		printf("child sid = %d\n",getsid(0));


		if(setpgid(0,getppid()) <0)
			perror("setpgid2");
		printf("child pid = %d, pgid = %d\n",getpid(),getpgid(0));
		sleep(3);
		exit(0);
	}else{

		printf("parent sid = %d\n",getsid(0));

		if(setpgid(pid,getpgid(0)) <0)
			perror("setpgid3");
		printf("parent pid = %d, pgid = %d\n",getpid(),getpgid(0));
	}

	waitpid(pid,0,0);

	exit(0);
}
