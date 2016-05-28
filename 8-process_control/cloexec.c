#include <apue.h>

int main(int argc ,char *argv[])
{
	int var = 10;
	pid_t pid;
	
	int fd = open("test.out",O_RDWR | O_CREAT | O_CLOEXEC);
	
	printf("before fork...\n");
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid==0){
		execlp("ls",".",NULL);	
		if(write(fd,"son",3) != 3)
			perror("write son");
		exit(0);
	}
	else{
		if(write(fd,"parent",6) != 6)
			perror("write parent");
		sleep(2);
	}

	exit(0);
}
