#include<stdio.h>
#define maxSize 1000
typedef int dataType;
typedef struct eStr{
	dataType data[maxSize];
	int higN;
	int midN;
	int lowN;
}eStr;
eStr Str;
int Loc=0;
int createStr(eStr *S,int a[],int l){
	for(int i=1;i<=l;i++){
		S->data[i]=a[i];
	}
	S->higN=l;
	S->lowN=1;
	S->midN=(S->higN+S->lowN)/2;
	return 1;
}
int findEle(eStr *S,int e,int &Loc){
	int Ele=e;
	if(S->higN<S->lowN){
		return 0;
	}
	if(e>S->data[S->midN]){
		S->lowN=S->midN+1;
		S->midN=(S->higN+S->lowN)/2;
		findEle(&Str,Ele,Loc);
	}else if(e<S->data[S->midN]){
		S->higN=S->midN-1;
		S->midN=(S->higN+S->lowN)/2;
		findEle(&Str,Ele,Loc);
	}else if(e==S->data[S->midN]){
		Loc=S->midN;
		return 1;
	} 
}
int main(){

	int l,a[maxSize];
	printf("请输入元素个数:"); 
	scanf("%d",&l);
	printf("\n请输入一个递增（递减）的有序表:"); 
	for(int i=1;i<=l;i++){
		scanf("%d",&a[i]);
	}
	createStr(&Str,a,l);
	int Ele;
	scanf("%d",&Ele);
	if(findEle(&Str,Ele,Loc)){
		printf("所在位置为：%d",Loc);
	}else{
		printf("未找到！");
	}
}
