#include <apue.h>
#include <sys/shm.h>

int main(int argc,char *argv[])
{
	int shm_id;
	key_t key;
	char *ptr;
	int i;

	if((key = ftok("/",3)) < 0)
		perror("ftok");

	if((shm_id = shmget(key,100,0666 | IPC_CREAT)) < 0)
		perror("shmget");
	else printf("shm_id = %d\n",shm_id);


	if((ptr = shmat(shm_id,0,SHM_RND)) < 0)
		perror("shmat");
	else printf("ptr = %p\n",ptr);

	memset(ptr,'\0',100);
	for(i=0;i<10;i++){
		strncpy(ptr,"hello",5);
		sleep(1);
	}

	sleep(30);

	if(shmdt(ptr) <0)
		perror("shmdt");

	if(shmctl(shm_id,IPC_RMID,0) <0)
		perror("shmctl");
	else printf("delete shm success\n");	

	exit(0);
}
