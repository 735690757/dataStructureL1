#include<stdio.h>
 
#include<stdlib.h>
#include<windows.h>
#define MaxV 500
#define NVn 19//g->n=19;
#define NVe 24//g->e=24;
typedef struct{
	int no;//编号 
	char info[MaxV];//简介 
	char infoX[MaxV];
}VertexType;
typedef struct{
	int edges[MaxV][MaxV];//邻接矩阵 
	int n,e;//顶点，边 
	VertexType vexs[MaxV];
}MGraph;
void Headline(){
	printf("--------------------------------------------\n");
	printf("              景点旅行系统                  \n");
	printf("--------------------------------------------\n");
}
void windows_cmd_support_utf8(void){
#ifdef WIN32
    system("chcp 65001 & cls");
#endif
}
void windows_cmd_support_GBK(void){
#ifdef WIN32
    system("chcp 936 & cls");
#endif
}
MGraph *create(MGraph *g){
	Headline();
	int i=0;
	int j=0;
	g=(MGraph*)malloc(sizeof(MGraph));
	g->n=NVn;
	g->e=NVe;
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("inf.txt","r");
	fp2=fopen("edge.txt","r");
	for(int x=0;x<g->n;x++){
		g->vexs[i].no=i;
		fflush(stdin);
		fscanf(fp1,"%s",&g->vexs[i].info);
		fscanf(fp1,"%s",&g->vexs[i].infoX);
		i++;
	}
	for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			fflush(stdin);
			fscanf(fp2,"%d",&g->edges[i][j]);
		}
	}
	return g;
}
int Prim(MGraph *M){//Prim算法 
	Headline();
	int adjvex[MaxV],lowcost[MaxV];//分别为邻接点与最小权值 
	lowcost[MaxV]=0;
	int sum=0;
	int zancMinex=8000; 
	int zancFlag=0;//标志，用于赋值 
	int zancMinerc=0;
//从此开始 
	for(int j=0;j<M->n;j++){
			lowcost[j]=M->edges[j][0];
			adjvex[j]=0;
		}
	for(int i=1;i<M->n;i++){
		for(int w=0;w<M->n;w++){
			printf("%d ",adjvex[w]);
		}
		printf("\n");
		for(int w=0;w<M->n;w++){
			printf("%d ",lowcost[w]);
		}
		printf("\n");
//至此结束，均为内容展示，不涉及算法内容 
		for(int j=0;j<M->n;j++){
			if(lowcost[j]<zancMinex&&lowcost[j]!=0){
			//如果找到一个比原有权值更小的数值，那么就对其进行更新迭代 
				zancFlag=j;//更新标志 
				zancMinerc=lowcost[j];//更新最小权值 
			}
		}
		printf("%d\n",zancFlag);

		lowcost[zancFlag]=0;
		for(int i=0;i<M->n;i++){
			if(M->edges[i][zancFlag]<lowcost[i]&&lowcost[i]!=0){
				lowcost[i]=M->edges[i][zancFlag];
				adjvex[i]=zancFlag;
			}
		}
		zancMinex=8000;//重新置为伪无穷 
		sum+=zancMinerc;//权值求和，计算造价 
		printf("目前长度：%d\n",sum);
	}
	printf("全程最小造价：%d",sum);
	return sum;
	
}
int vist[MaxV]={0};//检查其是否被访问过
void Rec(){
	Headline();
	windows_cmd_support_utf8();
	printf("Recommended tour routes are as follows:");
}
int p=0; 
int sta=0;
int DFS(MGraph *M,int v){//深度优先遍历 
	
	printf("-->%s",M->vexs[v].info);
	vist[v]=1;
	if(sta){
		return 0;
	}
	if(v==p){
		sta=1;
		
	}
	
	for(int j=0;j<M->n;j++){
		if(M->edges[v][j]<7000&&M->edges[v][j]!=0&&vist[j]==0){
			Sleep(500);
			if(sta){
				return 0;
			}
			DFS(M,j);
		}
	}
}
void show(MGraph *g){
	int i,j,k=0;
	Headline();
	printf("\n输出公园信息:\n");
	for(i=0;i<g->n;i++){
		printf("	%d	|	",i);
		for(j=0;j<g->n;j++){
			k++;
			if(g->edges[i][j]>7000){
				printf("∞  ");	
			}else{
				printf("%d  ",g->edges[i][j]);
			}
			if(k%19==0){
				printf("		|\n");
			}
		}
	}
}
void Tell(MGraph *g){
	Headline();
	windows_cmd_support_utf8();
	
	for(int i=0;i<g->n;i++){
		printf("%d.",g->vexs[i].no);
		printf("%s			",g->vexs[i].info);
		printf("%s\n",g->vexs[i].infoX);
	}
}
int main(){
	
	MGraph *M=NULL;
	M=create(M);
	while(1){
		windows_cmd_support_GBK();
		system("cls");
		Headline(); 
		printf("1.公园景点介绍\n"); 
		printf("2.公园邻接矩阵展示\n");
		printf("3.全程最佳管道维修路径\n");
		printf("4.从起点出发，到某一节点的路径长度\n");
		printf("5.退出系统\n\n\n\n\n");
		printf("请选择相应的功能（1-5）:");
		int select;
		scanf("%d",&select);
		while(1){
			windows_cmd_support_GBK();
			if(select<=5&&select>0){
				break;
			}else{
				printf("输入无效，请重新选择："); 
				fflush(stdin);
				scanf("%d",&select);
			}
		}
		switch(select){
			
			case 1:{
				Tell(M);
				system("pause");
				break;
			}
			case 2:{
				show(M);
				system("pause");
				break;
			}
			case 3:{
				Prim(M);
				system("pause");
				break;
			}
			case 4:{
				Tell(M);
				scanf("%d",&p);
				Rec();
				Sleep(1000);
				DFS(M,0);
				sta=0;
				system("pause");
				break;
			}
			case 5:{
				printf("再见！");
				return 0;
			}	
		}
	}
} 
