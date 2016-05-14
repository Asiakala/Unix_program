#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char * argv[])
{
	FILE * fp;
	char buff[20];
	
	if((fp = fopen("test.txt","a"))==NULL){
		perror("fopen");
		exit(-1);
	}

	strcpy(buff,"this is a test!");
	fwrite(buff,sizeof(buff),1,fp);

	printf("sleeping\n");
	sleep(10);
	printf("wakeup!\n");

	fclose(fp);

	exit(0);
}
