#include <apue.h>

#ifdef SOLARIS
	#define PSCMD "ps -a -o pid,ppid,s,tty,comm"
#else
	#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif

int main(int argc,char *argv[])
{
	pid_t pid;

	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0)
		exit(0);

	system(PSCMD);
	sleep(4);
	
	exit(0);
}
