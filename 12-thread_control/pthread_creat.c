#include <apue.h>
#include <pthread.h>

#define SIZE 10

pthread_t ntid[SIZE];

void printids(const char *str)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid = %lu tid = %lu (0x%lx)\n",str,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}

//void print_thread_attribute(pthread_t)

void *thread_func1(void *arg)
{	
	printids("new thread1:");
	return((void *)1);
}

void *thread_func2(void *arg)
{
	printids("new thread2:");
	pthread_exit((void *)2);
}

int main(int argc,char *argv[])
{
	int err;
	void *tret;

	err = pthread_create(&ntid[0],NULL,thread_func1,NULL);
	if(err != 0)
		printf("pthread_creat error!\n");
	err = pthread_create(&ntid[1],NULL,thread_func2,NULL);
	if(err != 0)
		printf("pthread_creat error!\n");

	if((err = pthread_join(ntid[0],&tret)) != 0)
		printf("pthread_join error!\n");
	else printf("thread1 exit code %ld\n",(long)tret);
	
	if((err = pthread_join(ntid[1],&tret)) != 0)
		printf("pthread_join error!\n");
	else printf("thread2 exit code %ld\n",(long)tret);

	printids("main thread:");
	
	exit(0);
}
