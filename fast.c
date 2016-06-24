#include <stdio.h>
#include <stdlib.h>

void print(int *data,int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
}

int fast(int *data,int head,int tail)
{
	int key,j,k;
	int temp;
	if(head == tail) return 0;
	
	i = head;
	j = head+1;
	k = tail;
	while(j!=k){	
		while(data[j]>data[i] && j!=k){
			j++;
			if(j==k){
				break;
			}
		}
		
		if(data[i]>data[j]){
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i = j;
		}
		if(j==k){
			if(j>head) fast(data,head,j-1);
			if(k<tail) fast(data,k+1,tail);
		}
		if(j<k) j++;	

		while(data[k]>data[i] && j!=k){
			k--;
			if(j==k){
				break;
			}
		}
	
		if(data[i]>data[k]){
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
			i = k;
		}
		if(j==k){
			if(j>head) fast(data,head,j-1);
			if(k<tail) fast(data,k+1,tail);
		}
		if(k>j)k--;	
	}
	
	if(data[i]>data[k] && j!=k){
		temp = data[i];
		data[i] = data[k];
		data[k] = temp;	
	}
	if(j>head) fast(data,head,j-1);
	if(k<tail) fast(data,k+1,tail);
	
	return 0;
}

int main(int argc,char *argv[])
{
	int len = 0;
	int data[100];
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
	}

	return 0;
}
