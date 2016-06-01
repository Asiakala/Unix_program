#include <apue.h>
#include <errno.h>
#include <signal.h>

static void sig_hup(int signo)
{
	printf("SIGHUP received,pid = %ld\n",(long)getpid());
}

static void sig_cont(int signo)
{
	printf("SIGCONT received,pid = %ld\n",(long)getpid());
}

static void sig_ttin(int signo)
{
	printf("SIGTTIN received,pid = %ld\n",(long)getpid());
}

static void pr_ids(char *name)
{
	printf("%s: pid = %ld,ppid = %ld,pgrp = %ld,tpgrp = %ld\n",name,(long)getpid(),(long)getppid(),(long)getpgrp(),(long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}

int main(int argc,char *argv[])
{
	char c;
	pid_t pid;

	pr_ids("parent");
	if((pid = fork()) < 0){
		perror("fork");
	}else if(pid>0){
		sleep(5);
	}else{
		pr_ids("child");
		signal(SIGHUP,sig_hup);
		signal(SIGCONT,sig_cont);
		signal(SIGTTIN,sig_ttin);
		kill(getpid(),SIGTSTP);
		pr_ids("child");
		if(read(STDIN_FILENO,&c,1) != 1){
			printf("read error %d on controlling TTY\n",errno);
		}
		printf("continue.....\n");
	}

	exit(0);
}
