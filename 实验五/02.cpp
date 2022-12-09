#include<stdio.h>
#include<malloc.h>
#define maxSize 1000
typedef int dataType;
typedef struct Node{
	dataType data;
	struct Node *lChild=NULL;//z
	struct Node *rChild=NULL;//y
}Node;
//二叉树结点创建
Node *CreateTreeNode(int x){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->lChild = NULL;
    p->rChild = NULL;
    return p;
}
//插入的递归算法
Node *Insert(Node *root, int x){
    if(root == NULL){
        root = CreateTreeNode(x);
        return root;
    }
    if(x < root->data){
        root->lChild = Insert(root->lChild, x);
    }
    if(x > root->data){
        root->rChild= Insert(root->rChild, x);
    }
    return root;
}
//查找的递归算法
Node *Search(Node *root, int x){
    if(root->data == x){
        return root;
    }else if(x < root->data){
        return Search(root->lChild, x);
    }else{
        return Search(root->rChild, x);
    }
}

int main(){
	int l,a[maxSize];
	printf("请输入元素个数:"); 
	scanf("%d",&l);
	printf("\n请输入相应的个数的数字:"); 
	for(int i=0;i<l;i++){
		fflush(stdin);
		scanf("%d",&a[i]);
	}
	Node *root;
	for(int i=0;i<l;i++){
		Insert(root,a[i]);
	}
	
	int E;
	scanf("%d",&E);
	Node *p=Search(root, E);
	printf("%d!!!!!",p->data);
}
