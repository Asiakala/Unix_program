#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc,char *argv[])
{
	char buf[100];
	struct timespec tsp;
	struct tm *tm;

	if(clock_gettime(CLOCK_REALTIME,&tsp)<0)
		perror("clock_gettime");

	printf("second = %ld,nanosecond = %ld\n",(long int)tsp.tv_sec,tsp.tv_nsec);
	
	tm = localtime(&tsp.tv_sec);	

	strftime(buf,100,"%r %F %A",tm);
	printf("%s\n",buf);

	exit(0);
}
