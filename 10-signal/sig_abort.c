#include <apue.h>
#include <signal.h>

int main(int argc,char *argv[])
{
	fprintf(stdout,"%s","abc");
//	fclose(stdout);
//	kill(getpid(),SIGABRT);
	abort();
	printf("end send abort signal\n");

	exit(0);
}
