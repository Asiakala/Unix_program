#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

int fuzhi(int i,int *j);

int main(int argc,char *argv[])
{
	int i,j;
	clock_t clk_ret;
	struct tms time;
	
	clk_ret = times(&time);
	printf("clk_ret = %ld\n",(long int)clk_ret);
	printf("time->utime = %ld\n",(long int)(time.tms_utime));
	printf("time->stime = %ld\n",(long int)(time.tms_stime));
	printf("time->cutime = %ld\n",(long int)(time.tms_cutime));
	printf("time->cstime = %ld\n",(long int)(time.tms_cstime));

	sleep(1);

	clk_ret = times(&time);
	printf("clk_ret = %ld\n",(long int)clk_ret);
	printf("time->utime = %ld\n",(long int)(time.tms_utime));
	printf("time->stime = %ld\n",(long int)(time.tms_stime));
	printf("time->cutime = %ld\n",(long int)(time.tms_cutime));
	printf("time->cstime = %ld\n",(long int)(time.tms_cstime));
	
	for(i=0;i<1000000;i++)
	{
		j = fuzhi(i,&j);
		printf("j = %d\n",j);
	}	

	clk_ret = times(&time);
	printf("clk_ret = %ld\n",(long int)clk_ret);
	printf("time->utime = %ld\n",(long int)(time.tms_utime));
	printf("time->stime = %ld\n",(long int)(time.tms_stime));
	printf("time->cutime = %ld\n",(long int)(time.tms_cutime));
	printf("time->cstime = %ld\n",(long int)(time.tms_cstime));
	
	exit(0);
}

int fuzhi(int i,int *j)
{
	*j = i;
	return *j;
}
