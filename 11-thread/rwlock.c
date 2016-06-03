#include <apue.h>
#include <pthread.h>

pthread_rwlock_t lock;
long int count1,count2;

void *thread_func1(void *arg)
{
	pthread_rwlock_wrlock(&lock);	
	printf("thread_func 1\n");
	count1++;
	pthread_rwlock_unlock(&lock);

	pthread_exit((void *)1);	
}

void *thread_func2(void *arg)
{
	pthread_rwlock_wrlock(&lock);	
	printf("thread_func 2\n");
	count2++;
	pthread_rwlock_unlock(&lock);

	pthread_exit((void *)2);	
}

int main(int argc,char *argv[])
{
	int err;
	void *ret; 
	pthread_t thread1,thread2;
	if((err = pthread_rwlock_init(&lock,NULL)) != 0)
		printf("pthread_rwlock_init err = %d\n",err);
	
	if((err = pthread_create(&thread1,NULL,thread_func1,NULL)) != 0)
		printf("pthread_create1 err = %d\n",err);
	
	if((err = pthread_create(&thread2,NULL,thread_func2,NULL)) != 0)
		printf("pthread_create2 err = %d\n",err);

	if(pthread_join(thread1,&ret) != 0)
		printf("pthread_join1 error\n");
	else printf("thread1 exit ret = %d\n",(int)ret);

	if(pthread_join(thread2,&ret) != 0)
		printf("pthread_join2 error\n");
	else printf("thread2 exit ret = %d\n",(int)ret);

	printf("count1 = %ld\n count2 = %ld\n",count1,count2);
	pthread_rwlock_destroy(&lock);

	exit(0);
}
