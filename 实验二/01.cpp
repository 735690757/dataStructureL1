//编程实现建栈、入栈、出栈操作
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
	creatStack(&stack,a,length);
	printf("内容展示：\n");
	showStack(&stack);
	printf("请输入一个元素压入以便于压入栈顶\n");
	scanf("%d",&element);
	if(Enter(&stack,element)){
		printf("成功！"); 
		printf("内容展示：\n");
		showStack(&stack);
	}else{
		printf("已经超长，无法入栈！"); 
	}
	if(Out(&stack,&ptr)){
		printf("已取出栈顶元素：%d\n",ptr); 
		printf("内容展示：\n");
		showStack(&stack);
	}else{
		printf("栈为空！");
	}
	return 0;
} 
