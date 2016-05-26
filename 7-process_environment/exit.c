#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void terminal_func0(void){
	printf("exit func0\n");
}

void terminal_func1(void){
	printf("exit func1\n");
}

void terminal_func2(void){
	printf("exit func2\n");
}

char buf[100];
char buf1[100];
char buf2[100];

int main(int argc,char *argv[])
{
	printf("hello china!\n");
	atexit(terminal_func0);
	atexit(terminal_func1);
	atexit(terminal_func2);
	//_exit(0);
	//exit(0);
	return 0;
	//_Exit(0);
}
