#include <apue.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include "my_head.h"

int main(int argc,char *argv[])
{
	int msg_id;
	char buf[100];
	msg msg[10];
	int i,ret;
	key_t key;

	if((key = ftok("/",1)) < 0)
		perror("ftok");
	if((msg_id = msgget(key,0666 | IPC_CREAT)) < 0)
		perror("msgget");
	else{
		printf("msg_id = %d\n",msg_id);
	
	}

	for(i=0;i<10;i++){
		msg[i].type = i+1;
		sprintf(buf,"%d",i);
		strcat(buf," message");
		printf("buf = %s\n",buf);
		memset(msg[i].text,'\0',100);
		strncpy(msg[i].text,buf,strlen(buf));
	}

	for(i=0;i<10;i++){
		if((ret = msgsnd(msg_id,&msg[i],100,IPC_NOWAIT)) < 0)
		{	
			if(ret == EAGAIN) printf("EAGAIN \n");
			else if(ret == EINTR) printf("EINTR\n");
			perror("msgsnd");
		}
		else {printf("send OK\n");}
		
	}	

	sleep(20);

	if(msgctl(msg_id,IPC_RMID,NULL) == 0)
		printf("delete success\n");
	else
		printf("delete failed\n");
	

	exit(0);
}
