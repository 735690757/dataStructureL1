//单链表的插入、删除操作的实现
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 1000
typedef int DataType;
int length;
typedef struct Node{
	DataType data;
	struct Node *next;
}Node; 
Node *CreatList(DataType a[],int n){
	Node *s=NULL;
	Node *r=NULL;
	Node *first=(Node *)malloc(sizeof(Node));
	r=first;
	for(int i=0;i<n;i++){
		s=(Node *)malloc(sizeof(Node));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return first;
}
int FindElement(Node *first,DataType E){
	int time=0;
	Node *p=first->next;
	while(p!=NULL){
		time++;
		if(p->data==E){
			return time;
		}
		p=p->next;
	}
	return 0;
}
int AddNode(Node *first,int Loc,DataType E){
	Node *p=first->next;
	Node *s=(Node *)malloc(sizeof(Node));
	s->data=E;
	for(int i=0;i<Loc-2;i++){
		p=p->next;
	}
	s->next=p->next;
	p->next=s;
	length++;
	return 1;
}
Node *DelNode(Node *first,int Loc){
	Node *p=first->next;
	for(int i=0;i<Loc-2;i++){
		p=p->next;
	}
	p->next=p->next->next;
	length--;
	return first;
}
void ShowSList(Node *first){
	Node *p=first->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	int zanc,a[MaxSize],E,Loc;
	Node *List;
	printf("请输入length：\n");
	scanf("%d",&length);
	if(length>MaxSize){
		printf("数目超长：\n");
		return 0; 
	}
	printf("请输入相应数量的元素：\n");
	for(int i=0;i<length;i++){
		scanf("%d",&a[i]);
	}
	List=CreatList(a,length);
	printf("内容展示：\n");
	ShowSList(List);

	printf("请输入要查找的元素：\n");
	scanf("%d",&E);
	if(Loc=FindElement(List,E)){
		printf("已找到！请输入要插入元素的值：\n");
		scanf("%d",&zanc);
		AddNode(List,Loc,zanc);
	}else{
		printf("未找到该元素，无法进行插入操作\n");
	}
	printf("内容展示：\n");
	ShowSList(List);

	printf("请输入要查找的元素：\n");
	scanf("%d",&E);
	if(Loc=FindElement(List,E)){
		printf("已找到！正在删除！：\n");
		
		List=DelNode(List,Loc);
	}else{
		printf("未找到该元素，无法进行删除操作\n");
	}
	printf("内容展示：\n");
	ShowSList(List);
	return 0;
}
