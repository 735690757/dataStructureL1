//应用最小生成树算法编制程序解决问题
#include<stdio.h>
#include<malloc.h>
#define maxSize 100
typedef char DataType; 
typedef struct{
	DataType vertex[maxSize];//节点元素 
	int edge[maxSize][maxSize];//边的权值存储 
	int verNum;//节点数目 
	int edgeNum;//边数目 
}MGraph; 
int vist[maxSize]={0};//检查其是否被访问过 
int CreatGraph(MGraph *M,DataType a[],int n,int e){//图的建立 
	M->edgeNum=n;
	M->verNum=e;
	M->edge[maxSize][maxSize]={0};
	for(int i=0;i<M->verNum;i++){
		M->vertex[i]=a[i];
	}
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			scanf("%d",&M->edge[i][j]);//双层循环输入权值 
		}
	}
}
void show(MGraph *M){//展示 
	printf("边矩阵展示：\n");
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			printf("%d ",M->edge[i][j]);
		}
		printf("\n");
	}
}
int Prim(MGraph *M){//Prim算法 
	int adjvex[maxSize],lowcost[maxSize];//分别为邻接点与最小权值 
	lowcost[maxSize]=0;
	int sum=0;
	int zancMinex=8888; 
	int zancFlag=0;//标志，用于赋值 
	int zancMinerc=0;
//从此开始 
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
//至此结束，均为内容展示，不涉及算法内容 
		for(int j=0;j<M->verNum;j++){
			if(lowcost[j]<zancMinex&&lowcost[j]!=0){
			//如果找到一个比原有权值更小的数值，那么就对其进行更新迭代 
				zancFlag=j;//更新标志 
				zancMinerc=lowcost[j];//更新最小权值 
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
		zancMinex=8888;//重新置为伪无穷 
		sum+=zancMinerc;//权值求和，计算造价 
	}
	printf("最小造价为：%d",sum);
	return sum;
	
}
int main(){
	MGraph MG;//图的实例化 
	int ver,edge;//节点与边数目的临时存储 
	DataType vT[maxSize];//节点内容的临时存储 
	printf("请输入节点数：\n");
	scanf("%d",&ver);
	printf("请输入边数：\n");
	scanf("%d",&edge);
	printf("请输入节点数据：\n");
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
