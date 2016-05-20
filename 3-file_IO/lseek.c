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

	if((cur_pos = lseek(STDIN_FILENO,0,SEEK_CUR)) == -1)
		printf("can't seek!\n");
	else
		printf("seek OK!\n");
	exit(0);
}

// ./lseek.out < test.txt              >>> seek OK!       file
// cat test.txt | ./lseek.out          >>> can't seek!    pipe
// ./lseek.out < /var/spool/cron/FIFO  >>> can't seek!    fifo
