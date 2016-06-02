#include <apue.h>
#include <fcntl.h>
#include <signal.h>

static void sig_int(int);
static void sig_quit(int);

int main(int argc,char *argv[])
{
	int i=0;
	struct sigaction act,oact;
	struct sigaction act_qt,oact_qt;

	printf("pid = %d\n",getpid());

	act.sa_handler = sig_int;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags = SA_RESTART;
	if(sigaction(SIGINT,&act,&oact) < 0)
		perror("sigaction1");
	
	act_qt.sa_handler = SIG_DFL;
	sigemptyset(&act_qt.sa_mask);
//	sigaddset(&act_qt.sa_mask,SIGQUIT);
	act_qt.sa_flags = SA_RESTART;
	if(sigaction(SIGQUIT,&act_qt,&oact_qt) < 0)
		perror("sigaction2");

	while(1){
//		sleep(5);	
		printf("while... i = %d\n",i);
		if(i++>3){
			act.sa_handler = sig_int;
			sigemptyset(&act.sa_mask);
			act.sa_flags = SA_RESTART;
			if(sigaction(SIGINT,&act,&oact) < 0)
				perror("sigaction1");
		}
		kill(getpid(),SIGINT);
	}

	exit(0);
}

static void sig_int(int sig)
{
	write(STDOUT_FILENO,"enter INT\n",10);
	sleep(3);
	write(STDOUT_FILENO,"exit INT\n",9);
}

static void sig_quit(int sig)
{
	write(STDOUT_FILENO,"enter QUIT\n",11);
	write(STDOUT_FILENO,"exit QUIT\n",10);
}
