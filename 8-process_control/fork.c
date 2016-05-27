#include <apue.h>

int global_var = 111;
char buf[] = "this is a test!";

int main(int argc ,char *argv[])
{
	int var = 10;
	pid_t pid;
	
	var = 11;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
		perror("write");
	sleep(1);
	printf("before fork...\n");
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid==0){
		var = 22;
		global_var = 222;
	printf("son pid = %d , ppid = %d , global_var = %d , var = %d\n",getpid(),getppid(),global_var,var);
	sleep(3);	
printf("son pid = %d , ppid = %d , global_var = %d , var = %d\n",getpid(),getppid(),global_var,var);
		exit(0);
//		write(fd,"son",3);
	}
	else{
		int fd = open("test.out",O_RDWR);
		write(fd,"parent",6);
//		sleep(2);
	}

	printf("pid = %d , ppid = %d , global_var = %d , var = %d\n",getpid(),getppid(),global_var,var);

	exit(0);
}
