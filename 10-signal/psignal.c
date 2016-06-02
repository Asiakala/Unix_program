#include <apue.h>
#include <signal.h>

int main(int argc,char *argv[])
{
	int i;
	for(i=0;i<32;i++){
		write(STDERR_FILENO,"	",1);
		psignal(i,NULL);
		printf("\n");
	}

	exit(0);
}
