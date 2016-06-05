#include <apue.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>

pr_mask(const char *str);

sigset_t mask;

void *thread_func(void *arg)
{
	pr_mask("thread_func");
	if(pthread_sigmask(SIG_UNBLOCK,&mask,NULL) < 0)
		perror("pthread_sigmask");
	pr_mask("thread_func");
	pthread_exit((void *)1);
}

int main(void)
{
	pthread_t tid;

	sigemptyset(&mask);
	sigaddset(&mask,SIGQUIT);
	if(pthread_sigmask(SIG_BLOCK,&mask,NULL) < 0)
		perror("sigprocmask");

	if(pthread_create(&tid,NULL,thread_func,NULL)<0){
		perror("pthread_create");
	}
	pr_mask("parent");
	
	sleep(1);
}

pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_save;
	
	errno_save = errno;
	if(pthread_sigmask(0,NULL,&sigset) < 0)
		perror("pthread_sigmask");
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
