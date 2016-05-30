#include <apue.h>

int main(int argc,char *argv[])
{
	int status;
	if((status = system("date")) < 0)
		perror("system");
	perror("status");

	if((status = system("cccc")) < 0)
		perror("system");
	perror("status");

	if((status = system("who; exit 44")) < 0)
		perror("system");
	perror("status");
	

	exit(0);
}
