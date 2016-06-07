#include <apue.h>

int main(void)
{
	char c;
	while((c = getchar()) != EOF){
		if(isupper(c))
			c = tolower(c);
		if(putchar(c) == EOF)
			perror("putchar");
		if(c == '\n')
			fflush(stdout);
	}
	exit(0);
}


