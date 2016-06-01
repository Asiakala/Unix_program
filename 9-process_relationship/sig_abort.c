#include <apue.h>
#include <signal.h>

int main(int argc,char *argv[])
{
	printf("send abort signal,pid = %d\n",getpid());
	kill(getpid(),SIGABRT);
	printf("end send abort signal\n");

	exit(0);
}
