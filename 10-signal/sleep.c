#include <apue.h>
#include <signal.h>

static void sig_usr1(int sig)
{
	printf("received SIGUSR1\n");
}

int main(int argc,char *argv[])
{
	int sec;

	printf("pid = %d\n",getpid());

	signal(SIGUSR1,sig_usr1);

	printf("sec = %d\n",sleep(60));

	exit(0);
}
