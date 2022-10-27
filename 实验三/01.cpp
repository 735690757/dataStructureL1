//��֪��չ���У�������к������ 
#include<stdio.h>
#include<malloc.h> 
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
void PreOrder(node* root){
	if(root==NULL) return;
	else{
		printf("%c",root->data);
		PreOrder(root->lChild);
		PreOrder(root->rChild);
	}
}
void InOrder(node* root){
	if(root==NULL) return;
	else{
		InOrder(root->lChild);
		printf("%c",root->data);
		InOrder(root->rChild);
	}
}
void PostOrder(node* root){
	if(root==NULL) return;
	else{
		PostOrder(root->lChild);
		PostOrder(root->rChild);
		printf("%c",root->data);
	}
}
int main(){
	node *root = NULL;
	printf("��������չ���������Խ�������"); 
	root = CreatTree(root);
	printf("���������"); 
	PreOrder(root);
	printf("\n"); 
	printf("���������"); 
	InOrder(root);
	printf("\n"); 
	printf("���������");
	PostOrder(root);
} 
