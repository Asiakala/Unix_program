#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc ,char *argv[])
{
	int fd;
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	printf("uid = %d\n",getuid());
	printf("euid = %d\n",geteuid());
	printf("gid = %d\n",getgid());
	printf("egid = %d\n",getegid());

	if(setuid(1000) != 0)
		perror("setuid");
	if((fd = open("/home/asia/test.txt",O_RDWR))<0)
		perror("open");
	
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	printf("uid = %d\n",getuid());
	printf("euid = %d\n",geteuid());
	printf("gid = %d\n",getgid());
	printf("egid = %d\n",getegid());

	exit(0);
}
