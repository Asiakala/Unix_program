#include <apue.h>
#include <errno.h>
#include <sys/sem.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

int get_sem(int sem_id){
	struct sembuf semoparray[1];
	semoparray[0].sem_num = 0;
	semoparray[0].sem_op = -1;
	semoparray[0].sem_flg = SEM_UNDO;

	if(semop(sem_id,semoparray,1) < 0){
		perror("semop");
		return -1;
	}
	else{ 
		printf("get sempo\n");
		return 0;
	}
}

int free_sem(int sem_id){
	struct sembuf semoparray[1];
	semoparray[0].sem_num = 0;
	semoparray[0].sem_op = 1;
	semoparray[0].sem_flg = SEM_UNDO;

	if(semop(sem_id,semoparray,1) < 0){
		perror("semop");
		return -1;
	}
	else{
	       	printf("free sempo\n");
		return 0;
	}
}
int main(int argc,char *argv[])
{
	pid_t pid;
	key_t key;
	int sem_id;
	struct semid_ds sem_ds;
	struct ipc_perm ipc;
	union semun semun;

	if((key = ftok("/",2)) < 0)
		perror("ftok");

	if((sem_id = semget(key,1,0666|IPC_CREAT)) < 0)
		perror("semget");
	else printf("sem_id = %d\n",sem_id);

/*
	ipc.mode = 0666;
	sem_ds.sem_perm = ipc;
	sem_ds.sem_otime = 0;
	sem_ds.sem_ctime = time(NULL);
	sem_ds.sem_nsems = 1;
*/	semun.val = 2;

	if(semctl(sem_id,0,SETVAL,semun) < 0)
		perror("semclt");
	else printf("semctl success\n");


	get_sem(sem_id);
	get_sem(sem_id);
	free_sem(sem_id);
	free_sem(sem_id);


	if(semctl(sem_id,0,IPC_RMID) < 0)
		perror("semclt");
	else printf("delete success\n");

	exit(0);
}
