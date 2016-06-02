#include <apue.h>
#include <signal.h>

static void sig_handle(int);

int flag = 0;

int main(int argc,char *argv[])
{
	signal(SIGALRM,sig_handle);
//	signal(SIGSTOP,sig_handle); // cat't be cat!
	signal(SIGTSTP,sig_handle);
	signal(SIGCHLD,sig_handle);
	signal(SIGABRT,sig_handle);
	signal(SIGINT,sig_handle);
	signal(SIGWINCH,sig_handle);
	alarm(10);

	while(flag == 0){
		;
	}
	
	exit(0);
}

static void sig_handle(int sig)
{
	if(sig == SIGALRM){
		printf("sig = %d ,received signal SIGALRM\n",sig);
		kill(getpid(),SIGABRT);
//		kill(getpid(),SIGSTOP);
//		flag = 1;
		
	}
	else if(sig == SIGHUP)
		printf("sig = %d ,received signal SIGHUP\n",sig);
	else if(sig == SIGQUIT)
		printf("sig = %d ,received signal SIGQUIT\n",sig);
	else if(sig == SIGABRT)
		printf("sig = %d ,received signal SIGABRT\n",sig);
	else if(sig == SIGKILL)
		printf("sig = %d ,received signal SIGKILL\n",sig);
	else if(sig == SIGTSTP)
		printf("sig = %d ,received signal SIGTSTP\n",sig);
	else if(sig == SIGCONT)
		printf("sig = %d ,received signal SIGCONT\n",sig);
	else if(sig == SIGCHLD)
		printf("sig = %d ,received signal SIGCHLD\n",sig);
	else if(sig == SIGINT)
		printf("sig = %d ,received signal SIGINT\n",sig);
	else if(sig == SIGWINCH)
		printf("sig = %d ,received signal SIGWINCH\n",sig);
	else{}
}
