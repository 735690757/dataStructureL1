//顺序表的插入、删除操作的实现
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
		printf("顺序表空间不够，无法建立顺序表\n");
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
		printf("Loc值大于length，无法作出添加操作\n");
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
		printf("顺序表中没有相应的元素，无法作出删除操作\n");
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
	printf("请输入length：\n");
	scanf("%d",&len);
	int a[1000];
	printf("请输入相应数量的元素：\n");
	for(int i=0;i<len;i++){
		scanf("%d",&a[i]);	
	} 
	CreateList(&SList,a,len);
	printf("内容展示：\n");
	ShowSList(&SList);
	printf("请输入添加元素实际位置的值：\n");
	scanf("%d",&loc);
	printf("请输入添加元素的值：\n");
	scanf("%d",&zanc);
	loc--;
	AddElement(&SList,loc,zanc);
	printf("内容展示：\n");
	ShowSList(&SList);
	printf("请输入需要删除的元素：\n");
	scanf("%d",&zanc);
	DeleteElement(&SList,zanc,&ptr);
	printf("内容展示：\n");
	ShowSList(&SList);
	return 0;
}
