//˳���Ĳ��롢ɾ��������ʵ��
#include<stdio.h>
#define MaxSize 1000
typedef int DataType;
typedef struct{
	DataType data[MaxSize];
	int length;
}SeqList;
void InitList(SeqList *L){
	L->length=0;
}
int CreateList(SeqList *L,DataType a[],int n){
	if(n>MaxSize){
		printf("˳���ռ䲻�����޷�����˳���\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		L->data[i]=a[i];
	}
	L->length=n;
	return 1;
}
int AddElement(SeqList *L,int Loc,DataType Element){
	if(Loc>L->length){
		printf("Locֵ����length���޷�������Ӳ���\n");
		return 0; 
	}
	for(int i=L->length;i>Loc;i--){
		L->data[i]=L->data[i-1];
	}
	L->data[Loc]=Element;
	L->length++;
}
int DeleteElement(SeqList *L,DataType Element,DataType *ptr){
	int Loc=-1;
	for(int i=0;i<L->length;i++){
		if(L->data[i]==Element){
			Loc=i;
			break;
		}
	}
	if(Loc==-1){
		printf("˳�����û����Ӧ��Ԫ�أ��޷�����ɾ������\n");
		return 0; 
	}
	*ptr=L->data[Loc];
	for(int j=Loc;j<L->length;j++){
		L->data[j]=L->data[j+1];
	}
	L->length--;
	return 0;
}
void ShowSList(SeqList *L){
	for(int i=0;i<L->length;i++){
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
int main(){
	int len,zanc,ptr,loc;
	SeqList SList;
	InitList(&SList);
	printf("������length��\n");
	scanf("%d",&len);
	int a[1000];
	printf("��������Ӧ������Ԫ�أ�\n");
	for(int i=0;i<len;i++){
		scanf("%d",&a[i]);	
	} 
	CreateList(&SList,a,len);
	printf("����չʾ��\n");
	ShowSList(&SList);
	printf("���������Ԫ��ʵ��λ�õ�ֵ��\n");
	scanf("%d",&loc);
	printf("���������Ԫ�ص�ֵ��\n");
	scanf("%d",&zanc);
	loc--;
	AddElement(&SList,loc,zanc);
	printf("����չʾ��\n");
	ShowSList(&SList);
	printf("��������Ҫɾ����Ԫ�أ�\n");
	scanf("%d",&zanc);
	DeleteElement(&SList,zanc,&ptr);
	printf("����չʾ��\n");
	ShowSList(&SList);
	return 0;
}
