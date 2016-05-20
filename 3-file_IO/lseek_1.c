#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd,len;
	off_t cur_pos;

	if((fd = open("test.txt",O_RDWR | O_CREAT,S_IRWXU))<0){
		perror("open");
	}

	if((cur_pos = lseek(fd,0,SEEK_CUR))==-1)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	printf("cur_pos = %ld\n",cur_pos);

	if((len = write(fd,"test lseek!",11))!=11){
		perror("write");
	}

	if((cur_pos = lseek(fd,0,SEEK_CUR))==-1)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	printf("cur_pos = %ld\n",cur_pos);

	if((cur_pos = lseek(fd,10000,SEEK_SET))==-1)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	printf("cur_pos = %ld\n",cur_pos);
	if((len = write(fd,"test lseek!",11))!=11){
		perror("write");
	}
	exit(0);
}
