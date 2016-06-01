#include <apue.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	pid_t sid;
	
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0){
		if(open("/dev/tty",O_RDONLY)<0)
			perror("open1");

		printf("child pid = %d,sid = %d\n",getpid(),getsid(0));
		if((sid = setsid()) < 0)
			perror("setsid");

		if(open("/dev/tty",O_RDONLY)<0)
			perror("open2");
		
		printf("child pid = %d,sid = %d\n",getpid(),getsid(0));
		write(STDOUT_FILENO,"hello",5);
	}else{
		printf("parent pid = %d,sid = %d\n",getpid(),getsid(0));
		sleep(5);
	}

	exit(0);
}
