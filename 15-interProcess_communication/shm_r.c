#include <apue.h>
#include <sys/shm.h>

int main(int argc,char *argv[])
{
	int shm_id;
	key_t key;
	char *ptr;
	char buf[100];

	if((key = ftok("/",3)) < 0)
		perror("ftok");

	if((shm_id = shmget(key,100,0666)) < 0)
		perror("shmget");
	else printf("shm_id = %d\n",shm_id);

	memset(buf,'\0',100);
	if((ptr = shmat(shm_id,0,SHM_RND)) < 0)
		perror("shmat");

	strncpy(buf,ptr,100);
	printf("buf = %s\n",buf);
	printf("ptr = %p\n",ptr);

	if(shmdt(ptr) < 0)
		perror("shmdt");
	else printf("shmdt success\n");

	exit(0);
}
