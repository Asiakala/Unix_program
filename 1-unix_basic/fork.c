#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
	int status;
	pid_t pid;
	
	int fd1,fd2;


	printf("before fork...\n\n");
	if((pid = fork())<0){
		perror("fork");
	}
	else if(pid == 0){
		printf("this is child process...\n");
		if((fd2 = open("test.txt",O_RDWR))<0)
			perror("open");
		write(fd2,"child ",6);
		//execl("./io_line_buffer.out",(char *)0,NULL);
		//perror("execl");
	}
	else{
		if((fd1 = open("test.txt",O_RDWR))<0)
			perror("open");
		write(fd1,"father ",7);
	}
	
	printf("this is father process...\n");
	printf("wait for child exit...\n");
	if((pid = waitpid(pid,&status,0))<0){
		perror("waitpid");
	}

	printf("father exit...\n");
	exit(0);
}
