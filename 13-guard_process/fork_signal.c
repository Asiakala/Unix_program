#include <apue.h>
#include <signal.h>
#include <errno.h>

pr_mask(const char *str);

int main(void)
{
	pid_t pid;
	sigset_t mask;

	sigemptyset(&mask);
	sigaddset(&mask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&mask,NULL) < 0)
		perror("sigprocmask");

	if((pid = fork())<0)
		perror("fork");
	else if(pid == 0){
		pr_mask("child");
		if(sigprocmask(SIG_UNBLOCK,&mask,NULL) < 0)
			perror("sigprocmask");
		pr_mask("child");
		exit(1);
	}
	pr_mask("parent");
	
	sleep(1);
}

pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_save;
	
	errno_save = errno;
	if(sigprocmask(0,NULL,&sigset) < 0)
		perror("sigprocmask");
	else{
		printf("%s",str);
		if(sigismember(&sigset,SIGINT))
			printf(" SIGINT");
		if(sigismember(&sigset,SIGQUIT))
			printf(" SIGQUIT");
		if(sigismember(&sigset,SIGUSR1))
			printf(" SIGUSR1");
		if(sigismember(&sigset,SIGALRM))
			printf(" SIGALRM");
		
		printf("\n");
	}
	errno = errno_save;
}
