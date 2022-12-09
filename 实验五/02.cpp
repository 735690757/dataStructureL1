#include<stdio.h>
#include<malloc.h>
#define maxSize 1000
typedef int dataType;
typedef struct Node{
	dataType data;
	struct Node *lChild=NULL;//z
	struct Node *rChild=NULL;//y
}Node;
//��������㴴��
Node *CreateTreeNode(int x){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->lChild = NULL;
    p->rChild = NULL;
    return p;
}
//����ĵݹ��㷨
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
//���ҵĵݹ��㷨
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
	printf("������Ԫ�ظ���:"); 
	scanf("%d",&l);
	printf("\n��������Ӧ�ĸ���������:"); 
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
