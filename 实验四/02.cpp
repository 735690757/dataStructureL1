//Ӧ����С�������㷨���Ƴ���������
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
int CreatGraph(MGraph *M,DataType a[],int n,int e){//ͼ�Ľ��� 
	M->edgeNum=n;
	M->verNum=e;
	M->edge[maxSize][maxSize]={0};
	for(int i=0;i<M->verNum;i++){
		M->vertex[i]=a[i];
	}
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			scanf("%d",&M->edge[i][j]);//˫��ѭ������Ȩֵ 
		}
	}
}
void show(MGraph *M){//չʾ 
	printf("�߾���չʾ��\n");
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			printf("%d ",M->edge[i][j]);
		}
		printf("\n");
	}
}
int Prim(MGraph *M){//Prim�㷨 
	int adjvex[maxSize],lowcost[maxSize];//�ֱ�Ϊ�ڽӵ�����СȨֵ 
	lowcost[maxSize]=0;
	int sum=0;
	int zancMinex=8888; 
	int zancFlag=0;//��־�����ڸ�ֵ 
	int zancMinerc=0;
//�Ӵ˿�ʼ 
	for(int j=0;j<M->verNum;j++){
			lowcost[j]=M->edge[j][0];
			adjvex[j]=0;
		}
	for(int i=1;i<M->verNum;i++){
		for(int w=0;w<M->verNum;w++){
			printf("%d ",adjvex[w]);
		}
		printf("\n");
		for(int w=0;w<M->verNum;w++){
			printf("%d ",lowcost[w]);
		}
		printf("\n");
//���˽�������Ϊ����չʾ�����漰�㷨���� 
		for(int j=0;j<M->verNum;j++){
			if(lowcost[j]<zancMinex&&lowcost[j]!=0){
			//����ҵ�һ����ԭ��Ȩֵ��С����ֵ����ô�Ͷ�����и��µ��� 
				zancFlag=j;//���±�־ 
				zancMinerc=lowcost[j];//������СȨֵ 
			}
		}
		printf("%d\n",zancFlag);

		lowcost[zancFlag]=0;
		for(int i=0;i<M->verNum;i++){
			if(M->edge[i][zancFlag]<lowcost[i]&&lowcost[i]!=0){
				lowcost[i]=M->edge[i][zancFlag];
				adjvex[i]=zancFlag;
			}
		}
		zancMinex=8888;//������Ϊα���� 
		sum+=zancMinerc;//Ȩֵ��ͣ�������� 
	}
	printf("��С���Ϊ��%d",sum);
	return sum;
	
}
int main(){
	MGraph MG;//ͼ��ʵ���� 
	int ver,edge;//�ڵ������Ŀ����ʱ�洢 
	DataType vT[maxSize];//�ڵ����ݵ���ʱ�洢 
	printf("������ڵ�����\n");
	scanf("%d",&ver);
	printf("�����������\n");
	scanf("%d",&edge);
	printf("������ڵ����ݣ�\n");
	for(int i=0;i<ver;i++){
		getchar();
		scanf("%c",&vT[i]);
		//scanf("%d",&a[i]);
	}
	for(int i=0;i<ver;i++){
		printf("%c",vT[i]);
		//printf("%d",a[i]);
	}
	CreatGraph(&MG,vT,ver,edge);
	show(&MG);
	Prim(&MG);
	return 0;
} 
