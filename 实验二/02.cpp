//编程实现数制转换程序
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
int decimal_to_binary(Stack *S,int Dnum){
	int zanc=Dnum;
	while(zanc>=2){
		S->top++;
		S->Sta[S->top]=zanc%2;
		zanc=zanc/2;
	}
	S->top++;
	S->Sta[S->top]=zanc;
	return 1; 
}
int decimal_to_octal(Stack *S,int Dnum){
	int zanc=Dnum;
	while(zanc>=8){
		S->top++;
		S->Sta[S->top]=zanc%8;
		zanc=zanc/8;
	}
	S->top++;
	S->Sta[S->top]=zanc;
	return 1; 
}
void showBinary(Stack *S){
	for(int i=S->top;i>=0;i--){
		printf("%d ",S->Sta[i]);
	}
	printf("\n");
}
int main(){
	int length,a[MaxSize],decimal; 
	Stack stack_B;
	initialStack(&stack_B);
	printf("十进制转二进制；\n"); 
	scanf("%d",&decimal);
	decimal_to_binary(&stack_B,decimal);
	showBinary(&stack_B);
	printf("十进制转八进制；\n");
	Stack stack_O;
	initialStack(&stack_O);
	scanf("%d",&decimal);
	decimal_to_octal(&stack_O,decimal);
	showBinary(&stack_O);
	return 0;
}
