#include <apue.h>

int main(int argc,char *argv[])
{
	int fd;
	int ret;

	if(mkfifo("./myfifo",0777) < 0)
		perror("mkfifo");
	if((fd = open("./myfifo",O_WRONLY)) < 0)
		perror("open");

	printf("fd = %d\n",fd);

	if((ret = write(fd,"OK",2)) != 2)
		perror("write");

	printf("write OK\n");
	sleep(1);
	if((ret = write(fd,"OK",2)) != 2)
		perror("write");

	sleep(30);
	exit(0);
}
