//编程实现队列的建立，在队列中插入元素和删除元素
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 8
typedef int DataType;
typedef struct{
	DataType Que[MaxSize];
	int Head;
	int Tail;
	int L;
}Queue; 
void initialQueue(Queue *Q){
	Q->Head=0;
	Q->Tail=-1;
	Q->L=0;
}
int creatQueue(Queue *Q,DataType a[],int l){
	for(int i=0;i<l;i++){
		Q->Que[i]=a[i];
		Q->Tail=(Q->Tail+1)%MaxSize;
		Q->L++;
	} 
}
int join(Queue *Q,int member){
	Q->L++;
	Q->Tail=(Q->Tail+1)%MaxSize;
	Q->Que[Q->Tail]=member;
	return 1;
}
int out(Queue *Q,DataType *ptr){
	*ptr=Q->Que[Q->Head];
	Q->Head=(Q->Head+1)%MaxSize;
	Q->L--; 
}
void showQueue(Queue *Q){
	for(int i=Q->Head;i<Q->L;i++){
		printf("%d ",Q->Que[i]);
	}
	printf("\n");
}
int main(){
	Queue queue;
	int length,a[MaxSize]; 
	DataType ptr,member;
	initialQueue(&queue);
	printf("请输入队列长度：\n");
	scanf("%d",&length);
	if(length>MaxSize){
		printf("数目超长：\n");
		return 0; 
	}
	printf("请输入相应数量的元素：\n");
	for(int i=0;i<length;i++){
		scanf("%d",&a[i]);
	}
	creatQueue(&queue,a,length);
	printf("队列展示：\n");
	showQueue(&queue);
	printf("请输入一个数字，进入队列；\n");
	scanf("%d",&member);
	join(&queue,member);
	printf("队列展示：\n");
	showQueue(&queue);
	out(&queue,&ptr);
	printf("队首出列，队列展示：\n");
	showQueue(&queue);
	
}
