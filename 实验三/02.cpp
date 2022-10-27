//非递归方案实现后序遍历 
#include<stdio.h>
#include<malloc.h> 
#define Max 1000
typedef char DataType;
typedef struct node{
	DataType data;
	struct node *lChild,*rChild; 
}node;
node* CreatTree(node* root){
	DataType ch;
	scanf("%c",&ch);
	if(ch=='#') root=NULL;
	else{
		root=(node *)malloc(sizeof(node));
		root->data=ch;
		root->lChild = CreatTree(root->lChild);
		root->rChild = CreatTree(root->rChild);
	}
	return root;
}

void InOrder(node* root){
	node *S[Max],*bt=root;
	int top=-1;
	while(bt!=NULL||top!=-1){
		while(bt!=NULL){
			S[++top]=bt;
			bt=bt->lChild;
		}
		if(top!=-1){
			bt=S[top--];
			printf("%c ",bt->data);
			bt=bt->rChild;
		}
	}
}
int main(){
	node *root = NULL;
	printf("请输入扩展先序序列以建立树："); 
	root = CreatTree(root);
	printf("后序遍历："); 
	InOrder(root);
} 
