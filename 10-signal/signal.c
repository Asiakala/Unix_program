#include <apue.h>
#include <signal.h>

static void sig_handle(int);

int main(int argc,char *argv[])
{
	if(signal(SIGUSR1,sig_handle) == SIG_ERR)
		perror("signal");
	if(signal(SIGUSR2,sig_handle) == SIG_ERR)
		perror("signal");

	for(;;){
		pause();
	}

	exit(0);
}

static void sig_handle(int signo)
{
	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else{
		printf("received signal %d\n",signo);
	}

}
