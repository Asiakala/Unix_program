#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int global_var = 111;
char buf[] = "this is a test!";

int main(int argc ,char *argv[])
{
	int var = 10;
	pid_t pid;
	
	var = 11;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
		perror("write");
	printf("before fork...\n");
	if((pid = vfork()) < 0)
		perror("fork");
	else if(pid==0){
	printf("son pid = %d , ppid = %d , global_var = %d , var = %d\n",getpid(),getppid(),global_var,var);
		var = 22;
		global_var = 222;
		exit(0);
//		write(fd,"son",3);
	}
	else{
		var = 11;
		int fd = open("test.out",O_RDWR);
		write(fd,"parent",6);
		sleep(60);
	}

	printf("pid = %d , ppid = %d , global_var = %d , var = %d\n",getpid(),getppid(),global_var,var);

	exit(0);
}
