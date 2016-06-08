#include <apue.h>
#include <sys/msg.h>
#include "my_head.h"
#include <errno.h>

int main(int argc,char *argv[])
{
	msg msg;
	int msg_id;
	int ret,i=10;
	key_t key;

	if((key = ftok("/",1)) <0)
		perror("ftok");
/*
	if(argc == 2)
		sscanf(argv[1],"%d",&msg_id);
	else return 0;
*/
	msg_id = msgget(key,0666);
	printf("msg_id = %d\n",msg_id);
	while(1){
		memset(&msg.text,'\0',100);
		if((ret = msgrcv(msg_id,&msg,100,i,0)) < 0){
			if(errno == EAGAIN) printf("EAGAIN\n");
			else if(errno == EINTR) printf("EINTR\n");
			else if(errno == EIDRM) {
				printf("EIDRM\n");
				return 1;
			}
			perror("msgrcv");
		}
		else{
			printf("msg.text = %s\n",msg.text);
		}
		i--;
	}

}
