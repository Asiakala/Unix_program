#include <apue.h>

int main(int argc,char *argv[])
{
	int i = 0;
	int ret;
	if((ret = execl("./argv.out","test",NULL)) == -1)
		perror("exec");


	exit(0);
}
