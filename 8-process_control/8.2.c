#include <apue.h>

static void f1(void),f2(void);

int main(int argc,char *argv[])
{
	f1();
	f2();	

	_exit(0);
}

static void f1(void)
{
	pid_t pid;

	if((pid = vfork())<0)
		perror("vfork");
}

static void f2(void)
{
	char buf[1000];
	int i;
	
	for(i=0;i<1000;i++)
		buf[i] = 0;
}
