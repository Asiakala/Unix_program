#include <apue.h>

int main(int argc,char *argv[])
{
	int fd;
	int ret;
	char buf[10];

	if(mkfifo("./myfifo",0777) < 0)
		perror("mkfifo");
	if((fd = open("./myfifo",O_RDONLY)) < 0)
		perror("open");

	printf("fd = %d\n",fd);

	if((ret = read(fd,buf,10)) != 2)
		perror("read");
	printf("read: buf = %s\n",buf);

	sleep(30);

	exit(0);
}
