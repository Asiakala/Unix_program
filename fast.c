#include <stdio.h>
#include <stdlib.h>

static int count = 0;

void print(int *data,int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
}

void swap_data(int * data,int j,int k)
{
	int temp;
	temp = data[j];
	data[j] = data[k];
	data[k] = temp;
	count++;
}

int fast(int *data,int head,int tail)
{
	int key,j,k;
	int temp;
	if(head >= tail) return 0;
	
	j = head;
	k = tail;
	key = data[head];

	while(j<k){	
		while(data[k]>=key && j<k){
			k--;
		}
		if(j<k){
			swap_data(data,j,k);
			j++;
		}
	
		while(data[j]<key && j<k){
			j++;
		}
		if(j<k){
			swap_data(data,j,k);
			k--;
		}
	}
	
	if(j>head) fast(data,head,j-1);
	if(k<tail) fast(data,k+1,tail);

	return 0;
}

int main(int argc,char *argv[])
{
	int data[100];
	int len = 0;
	int temp;
	while(1){
		len = 0;
		scanf("%d",&temp);
		while(temp!=-1){
			data[len++] = temp;
			scanf("%d",&temp);
		}
		printf("yuan:");
		print(data,len);
		fast(data,0,len-1);
		printf("fast:");
		print(data,len);
		printf("count = %d\n",count);
		count = 0;	
	}

	return 0;
}
