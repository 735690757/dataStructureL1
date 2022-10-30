//���ʵ��ͼ�ı���ͼ�㷨����ͼ��������������㷨�������������㷨������ 
#include<stdio.h>
#include<malloc.h>
#define maxSize 100
typedef char DataType; 
typedef struct{
	DataType vertex[maxSize];//�ڵ�Ԫ�� 
	int edge[maxSize][maxSize];//�ߵ�Ȩֵ�洢 
	int verNum;//�ڵ���Ŀ 
	int edgeNum;//����Ŀ 
}MGraph; 
int vist[maxSize]={0};//������Ƿ񱻷��ʹ� 
int DFS(MGraph *M,int v){//������ȱ��� 
	printf("%c",M->vertex[v]);
	vist[v]=1;
	for(int j=0;j<M->verNum;j++){
		if(M->edge[v][j]==1&&vist[j]==0){
			DFS(M,j);
		}
	}
}
int CreatGraph(MGraph *M,DataType a[],int n,int e){//����ͼ 
	M->edgeNum=n;
	M->verNum=e;
	M->edge[maxSize][maxSize]={0};//��ʼ�� 
	for(int i=0;i<M->verNum;i++){
		M->vertex[i]=a[i];
	}
	int zancL,zancR;//������ʱ�洢�������У� 
	for(int i=0;i<M->edgeNum;i++){
		printf("��������λ��\n");
		scanf("%d",&zancL);
		printf("��������λ��\n");
		scanf("%d",&zancR);
		M->edge[zancL][zancR]=1;
		M->edge[zancR][zancL]=1;//�˾���Ϊ�Գƾ�����Ҫ�Գ���1�������У� 
		printf("�ɹ���M%d%d��M%d%d�ѱ���1\n",zancL,zancR,zancR,zancL);
	}
//	for(int i=0;i<M->verNum;i++){
//		for(int j=0;j<M->verNum;j++){
//			scanf("%d",&M->edge[i][j]);
//		}
//	}
}
void show(MGraph *M){//ͼ��չʾ 
	printf("�߾���չʾ��\n");
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			printf("%d ",M->edge[i][j]);
		}
		printf("\n");
	}
}
int main(){
	MGraph MG;//�ṹ���ʵ������ʵ����ΪMG 
	int ver,edge;//���������ı���ڵ����ʱ�洢 
	DataType vT[maxSize];//�ڵ�Ԫ����ʱ�洢 
	printf("������ڵ�����\n");
	scanf("%d",&ver);
	printf("�����������\n");
	scanf("%d",&edge);
	printf("������ڵ����ݣ�\n");
	for(int i=0;i<ver;i++){
		getchar();
		scanf("%c",&vT[i]);
	}
	for(int i=0;i<ver;i++){
		printf("%c",vT[i]);
	}
	CreatGraph(&MG,vT,ver,edge);//���� 
	show(&MG);
	int start;
	printf("������������ȵ���ʼλ�ã�\n"); 
	scanf("%d",&start);
	DFS(&MG,start);//������� 
	return 0;
} 
