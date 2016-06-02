#include <apue.h>
#include <signal.h>

volatile sig_atomic_t quitflag;

static void sig_int(int sig)
{
	if(sig == SIGINT)
		printf("\ninterrupt\n");
	else if(sig == SIGQUIT)
		quitflag = 1;
}

int main(int argc ,char *argv[])
{
	sigset_t newmask,oldmask,zeromask;

	printf("pid = %d\n",getpid());

	if(signal(SIGINT,sig_int) == SIG_ERR)
		perror("signal1");
	if(signal(SIGQUIT,sig_int) == SIG_ERR)
		perror("signal2");

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask) < 0)
		perror("sigprocmask1");

	while(quitflag == 0)
		sigsuspend(&zeromask);

	quitflag = 0;

	if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0)
		perror("sigprocmask2");

	exit(0);
}
