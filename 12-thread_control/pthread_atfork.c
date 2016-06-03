#include <apue.h>
#include <pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void)
{
	int err;
	printf("prepare lock ...\n");
	if((err = pthread_mutex_lock(&lock1)) != 0)
		printf("pthread_mutex_lock error\n");
	if((err = pthread_mutex_lock(&lock2)) != 0)
		printf("pthread_mutex_lock error\n");
}

void parent(void)
{
	int err;
	printf("parent lock ...\n");
	if((err = pthread_mutex_unlock(&lock1)) != 0)
		printf("pthread_mutex_lock error\n");
	if((err = pthread_mutex_unlock(&lock2)) != 0)
		printf("pthread_mutex_lock error\n");
}

void child(void)
{
	int err;
	printf("child lock ...\n");
	if((err = pthread_mutex_unlock(&lock1)) != 0)
		printf("pthread_mutex_lock error\n");
	if((err = pthread_mutex_unlock(&lock2)) != 0)
		printf("pthread_mutex_lock error\n");
}

void *pthread_func(void *arg)
{
	printf("thread started...\n");
	pause();
	return 0;
}

int main(int argc,char *argv[])
{
	int err;
	pid_t pid;
	pthread_t tid;

	if((err = pthread_atfork(prepare,parent,child)) != 0)
		printf("pthread_atfork error\n");
	if((err = pthread_create(&tid,NULL,pthread_func,NULL)) != 0)
		printf("pthread_create error\n");

	sleep(2);
	printf("parent start to fork ...\n");

	if((pid = fork()) <0)
		perror("fork");
	else if(pid == 0)
		printf("child returned from fork\n");
	else
		printf("parent returned from fork\n");

	exit(0);
}
