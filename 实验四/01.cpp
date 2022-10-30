//编程实现图的遍历图算法（按图的深度优先搜索算法或广度优先搜索算法遍历） 
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
int DFS(MGraph *M,int v){//深度优先遍历 
	printf("%c",M->vertex[v]);
	vist[v]=1;
	for(int j=0;j<M->verNum;j++){
		if(M->edge[v][j]==1&&vist[j]==0){
			DFS(M,j);
		}
	}
}
int CreatGraph(MGraph *M,DataType a[],int n,int e){//创建图 
	M->edgeNum=n;
	M->verNum=e;
	M->edge[maxSize][maxSize]={0};//初始化 
	for(int i=0;i<M->verNum;i++){
		M->vertex[i]=a[i];
	}
	int zancL,zancR;//左右临时存储（行与列） 
	for(int i=0;i<M->edgeNum;i++){
		printf("请输入行位置\n");
		scanf("%d",&zancL);
		printf("请输入列位置\n");
		scanf("%d",&zancR);
		M->edge[zancL][zancR]=1;
		M->edge[zancR][zancL]=1;//此矩阵为对称矩阵，需要对称置1（行与列） 
		printf("成功！M%d%d与M%d%d已被置1\n",zancL,zancR,zancR,zancL);
	}
//	for(int i=0;i<M->verNum;i++){
//		for(int j=0;j<M->verNum;j++){
//			scanf("%d",&M->edge[i][j]);
//		}
//	}
}
void show(MGraph *M){//图的展示 
	printf("边矩阵展示：\n");
	for(int i=0;i<M->verNum;i++){
		for(int j=0;j<M->verNum;j++){
			printf("%d ",M->edge[i][j]);
		}
		printf("\n");
	}
}
int main(){
	MGraph MG;//结构体的实例化，实例化为MG 
	int ver,edge;//在主函数的边与节点的临时存储 
	DataType vT[maxSize];//节点元素临时存储 
	printf("请输入节点数：\n");
	scanf("%d",&ver);
	printf("请输入边数：\n");
	scanf("%d",&edge);
	printf("请输入节点数据：\n");
	for(int i=0;i<ver;i++){
		getchar();
		scanf("%c",&vT[i]);
	}
	for(int i=0;i<ver;i++){
		printf("%c",vT[i]);
	}
	CreatGraph(&MG,vT,ver,edge);//创建 
	show(&MG);
	int start;
	printf("请输入深度优先的起始位置：\n"); 
	scanf("%d",&start);
	DFS(&MG,start);//深度优先 
	return 0;
} 
