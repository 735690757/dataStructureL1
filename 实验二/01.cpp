//���ʵ�ֽ�ջ����ջ����ջ����
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 1000
typedef int DataType;
typedef struct{
	DataType Sta[MaxSize];
	int top;
}Stack; 
void initialStack(Stack *S){
	S->top=-1;
}
int creatStack(Stack *S,DataType a[],int L){
	for(int i=0;i<L;i++){
		S->top++;
		S->Sta[i]=a[i];
	}
	return 1;
}
int Out(Stack *S,DataType *ptr){
	if(S->top==-1){
		return 0; 
	}
	*ptr=S->Sta[S->top];
	S->top--;
}
int Enter(Stack *S,int element){
	if(S->top+1>MaxSize){
		return 0; 
	}
	S->top++;
	S->Sta[S->top]=element;
	return 1; 
}
void showStack(Stack *S){
	for(int i=0;i<S->top+1;i++){
		printf("%d ",S->Sta[i]);
	}
	printf("\n");
}
int main(){
	int length,a[MaxSize]; 
	DataType element;
	DataType ptr;
	Stack stack;
	initialStack(&stack);
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
	creatStack(&stack,a,length);
	printf("����չʾ��\n");
	showStack(&stack);
	printf("������һ��Ԫ��ѹ���Ա���ѹ��ջ��\n");
	scanf("%d",&element);
	if(Enter(&stack,element)){
		printf("�ɹ���"); 
		printf("����չʾ��\n");
		showStack(&stack);
	}else{
		printf("�Ѿ��������޷���ջ��"); 
	}
	if(Out(&stack,&ptr)){
		printf("��ȡ��ջ��Ԫ�أ�%d\n",ptr); 
		printf("����չʾ��\n");
		showStack(&stack);
	}else{
		printf("ջΪ�գ�");
	}
	return 0;
} 
