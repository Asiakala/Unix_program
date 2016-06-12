#include <termios.h>
#include <apue.h>

int main(int argc,char *argv[])
{
	struct termios term;

	if(tcgetattr(STDIN_FILENO,&term) < 0)
		perror("tcgetaddr");

	if(isatty(STDIN_FILENO) == 1)
		printf("is a tty!\n");
	else	printf("isn't a tty!\n");

	switch(term.c_cflag & CSIZE){
		case CS5:
			printf("5 bits/byte\n");
			break;
		case CS6:
			printf("6 bits/byte\n");
			break;
		case CS7:
			printf("7 bits/byte\n");
			break;
		case CS8:
			printf("8 bits/byte\n");
			break;
		default:
			printf("unknown bits/byte\n");
			break;
	}

	term.c_cflag &= ~CSIZE;
	term.c_cflag |= CS8;
	if(tcsetattr(STDIN_FILENO,TCSANOW,&term) <0)
		perror("tcsetattr");

	char *ptr = NULL;
	printf("tty = %s\n",ctermid(ptr));
	printf("fd 0: %s\n",isatty(0)?"tty":"not a tty");
	printf("fd 1: %s\n",isatty(1)?"tty":"not a tty");
	printf("fd 2: %s\n",isatty(2)?"tty":"not a tty");

	char *name;
	printf("fd 0 ttyname = %s\n",ttyname(0));	
	printf("fd 1 ttyname = %s\n",ttyname(1));	
	printf("fd 2 ttyname = %s\n",ttyname(2));	
	exit(0);
}
