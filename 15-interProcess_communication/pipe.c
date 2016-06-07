#include <apue.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int pfd[2];
	if(pipe(pfd) < 0)
		perror("pipe");

	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0){
		int len;
		char buf[10];
		memset(buf,'\0',10);
		
		close(pfd[1]);
		len = read(pfd[0],buf,2);
		printf("buf = %s\n",buf);
		sleep(1);
		exit(0);
	}

	close(pfd[0]);
	sleep(2);
	write(pfd[1],"OK",2);

	waitpid(pid,0,0);

	exit(0);
}
