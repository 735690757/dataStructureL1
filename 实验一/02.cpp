//������Ĳ��롢ɾ��������ʵ��
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
	printf("������length��\n");
	scanf("%d",&length);
	if(length>MaxSize){
		printf("��Ŀ������\n");
		return 0; 
	}
	printf("��������Ӧ������Ԫ�أ�\n");
	for(int i=0;i<length;i++){
		scanf("%d",&a[i]);
	}
	List=CreatList(a,length);
	printf("����չʾ��\n");
	ShowSList(List);

	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d",&E);
	if(Loc=FindElement(List,E)){
		printf("���ҵ���������Ҫ����Ԫ�ص�ֵ��\n");
		scanf("%d",&zanc);
		AddNode(List,Loc,zanc);
	}else{
		printf("δ�ҵ���Ԫ�أ��޷����в������\n");
	}
	printf("����չʾ��\n");
	ShowSList(List);

	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d",&E);
	if(Loc=FindElement(List,E)){
		printf("���ҵ�������ɾ������\n");
		
		List=DelNode(List,Loc);
	}else{
		printf("δ�ҵ���Ԫ�أ��޷�����ɾ������\n");
	}
	printf("����չʾ��\n");
	ShowSList(List);
	return 0;
}
