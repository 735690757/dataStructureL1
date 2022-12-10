#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//结构体设计及其宏定义规范由刘珂瑞与范飞龙共同完成
//程序主函数由刘珂瑞设计编写 
#define V 11
#define E 15
//15条边、11个节点 
#define maxSize 1000
#define maxWeight 8888					//不可达 
typedef struct Node{					//学校各个节点信息 
	char name[maxSize];  				//顶点名称 
	int X; 								//代号 
	char introduction[maxSize*10];   	//顶点简介
}Node;
typedef struct Graph{			//图 
 	Node nodes[12];   			//十一个顶点 
 	int Weight[20][20];   		//权值
 	int vnum;					//顶点数
	int edge;    				//边数 
}Graph;
//子函数统一规范如下： 
int CreateGraph(Graph* G);				//主图（无向有权）信息导入			**范飞龙** 
int CreateGraph_forZanc(Graph* G);		//从图（可达）信息导入				**刘珂瑞**
Graph* Find(Graph *G);					//主图（无向有权）的弗洛伊德算法	**刘珂瑞**
Graph* Find_forZanc(Graph *G);			//从图（可达）的弗洛伊德算法		**刘珂瑞**
void Headline();						//常驻短标题						**李启睿**
void Headline_Long();					//常驻长标题						**李启睿**
void introduce(Graph *G);				//节点信息介绍						**李启睿**
void Show(Graph *G);					//节点邻接矩阵展示					**洪天宝** 
void canGo(Graph* G);					//一步直达节点信息展示				**洪天宝** 
										//main()							**刘珂瑞**
int CreateGraph(Graph* G){//**范飞龙** 
	G->edge=E;	//15条边
	G->vnum=V;	//11个顶点
	for(int i=1;i<=G->vnum;i++){		//初始化节点代号 
		G->nodes[i].X=i;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int w=1;w<=G->vnum;w++){
			G->Weight[i][w]=maxWeight;			//初始化节点权值为不可达:"maxWeight" 
		}
	}
	FILE *fp;
	fp = fopen("Weight.txt", "r");
	
	int u,i,w; 
	for(int i=1;i<=E;i++){
		fscanf(fp, "%d %d %d", &u,&i,&w);
		G->Weight[u][i]=G->Weight[i][u]=w;
	}	
	fp = fopen("NodeName.txt", "r");
	for(int i=1;i<=V;i++){
		fscanf(fp, "%s", &G->nodes[i].name);
	}
	fp = fopen("Introduction.txt", "r");
	for(int i=1;i<=V;i++){
		fscanf(fp, "%s", &G->nodes[i].introduction);
	}
	fclose(fp);
	return 1; 
}

int CreateGraph_forZanc(Graph* G){//**刘珂瑞** 
	G->edge=E;	//15条边
	G->vnum=V;	//11个顶点
	for(int i=1;i<=G->vnum;i++){		//初始化节点代号 
		G->nodes[i].X=i;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int w=1;w<=G->vnum;w++){
			G->Weight[i][w]=maxWeight;			//初始化节点权值为不可达:"maxWeight" 
		}
	} 
	FILE *fp;
	int u,i,w; 
	fp = fopen("Weight.txt", "r");
	for(int i=1;i<=E;i++){
		fscanf(fp, "%d %d %d", &u,&i,&w);
		G->Weight[u][i]=G->Weight[i][u]=1;		//可达 
	}
	fp = fopen("NodeName.txt", "r");
	for(int i=1;i<=V;i++){
		fscanf(fp, "%s", &G->nodes[i].name);
	}
	fp = fopen("Introduction.txt", "r");
	for(int i=1;i<=V;i++){
		fscanf(fp, "%s", &G->nodes[i].introduction);
	}
	fclose(fp);
	return 1;
}
int dist[maxSize][maxSize];				//存放最短路径长度 初始为图的邻接矩阵 
int path[maxSize][maxSize];				//存放从Vi到Vj的最短路径 初始为path[i][j]="ViVj" 
Graph* Find(Graph *G){	//**刘珂瑞**		
	for(int p=1;p<=G->vnum;p++){		//自己与自己完全可达置为0 
		G->Weight[p][p]=0;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int j=1;j<=G->vnum;j++){
			dist[i][j]=G->Weight[i][j]; 	//两点间最短路径,初始化为两点间权值 
			path[i][j]=j;   				//最短路径的上一个点  
		}
	}
	//弗洛伊德算法
	for(int k=1;k<=G->vnum;k++){
		for(int i=1;i<=G->vnum;i++){
			for(int j=1;j<=G->vnum;j++){  
				if(dist[i][j]>(dist[i][k]+dist[k][j])){
					path[i][j]=path[i][k];
					dist[i][j]=dist[i][k]+dist[k][j]; 
				}
			}
		}
	}
} 
int dist_forZanc[maxSize][maxSize];				//存放最短路径长度 初始为图的邻接矩阵 
int path_forZanc[maxSize][maxSize];	
Graph* Find_forZanc(Graph *G){	//**刘珂瑞**		
	for(int p=1;p<=G->vnum;p++){		//自己与自己完全可达置为0 
		G->Weight[p][p]=0;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int j=1;j<=G->vnum;j++){
			dist_forZanc[i][j]=G->Weight[i][j]; 	//两点间最短路径,初始化为两点间权值 
			path_forZanc[i][j]=j;   				//最短路径的上一个点 
		}
	}
	//弗洛伊德算法
	for(int k=1;k<=G->vnum;k++){
		for(int i=1;i<=G->vnum;i++){
			for(int j=1;j<=G->vnum;j++){  
				if(dist_forZanc[i][j]>(dist_forZanc[i][k]+dist_forZanc[k][j])){
					path_forZanc[i][j]=path_forZanc[i][k];
					dist_forZanc[i][j]=dist_forZanc[i][k]+dist_forZanc[k][j]; 
				}
			}
		}
	}
} 
void Headline(){//**李启睿** 
	printf("--------------------------------------------\n");
	printf("               校园导航系统                 \n");
	printf("--------------------------------------------\n");
}
void Headline_Long(){//**李启睿** 
	printf("---------------------------------------------------------------------------------------------------------\n\n");
	printf("               					校园导航系统								                 \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
}
void introduce(Graph *G){//**李启睿** 
//介绍 
	system("cls");		//cmd清屏 
	Headline();
	printf("序号	名称		介绍\n"); 
	for(int i=1;i<=G->vnum;i++){
		printf("%d	%s		%s\n",G->nodes[i].X,G->nodes[i].name,G->nodes[i].introduction);
	}
	system("pause");	//cmd暂停 
}
void Show(Graph *G){//**洪天宝** 
	system("cls");
	Headline_Long();
	printf("	");
	for(int k=1;k<=G->vnum;k++){
			printf("%s	",G->nodes[k].name);
	}
		printf("\n");
	for(int i=1;i<=G->vnum;i++){
		printf("|	");
		
		for(int j=1;j<=G->vnum;j++){
			
			if(G->Weight[i][j]==8888){
				printf("∞	");
			}else{
				printf("%d	",G->Weight[i][j]);
			}
			
		}
		printf("	|\n");
	}
	printf("\n\n\n\n	****	∞为不可直达！	****	\n\n\n\n");
	system("pause");
}
void canGo(Graph* G){//**洪天宝** 
	introduce(G);
	printf("你在哪呢？\n请输入：");
	int loc;
	scanf("%d",&loc);
	printf("你可以直达如下地点：\n"); 
	for(int i=1;i<=E;i++){
			if(G->Weight[loc][i]==1){
				printf("%s\n",G->nodes[i].name);
		}
	}
	system("pause");
}
int main(){//**刘珂瑞** 
	int time;		//需要行走的次数 
	Graph *G;		//核心权值图 
	Graph *GZanc;	//可达图
	G=(Graph*)malloc(sizeof(Graph));
	GZanc=(Graph*)malloc(sizeof(Graph));
	
	for(int q=1;q<=E;q++){
		for(int w=1;w<=E;w++){
 			dist[q][w]=maxWeight;    //初始化
 		}
	}
	
	CreateGraph(G);
	CreateGraph_forZanc(GZanc);
	Find_forZanc(GZanc);
	Find(G);
	
	
	int sta,end,mid;
	while(1){
		system("cls");
		Headline();
		printf("1.校园节点介绍！\n"); 
		printf("2.地图邻接矩阵展示！\n");
		printf("3.我能往哪里走？\n"); 
		printf("4.需要导航？选我就对了！(如果你想少走一些路的话)\n");
		printf("5.需要导航？选我最靠谱！(如果你想经过一些建筑的话)\n");
		printf("6.退出系统\n\n\n\n\n");
		printf("				组长：刘珂瑞\n				组员：范飞龙、李启睿、洪天宝\n				谢谢可爱的组员们！！\n"); 
		printf("请选择相应的功能（1-5）:");
		int select;
		scanf("%d",&select);
		while(1){
			if(select<=6&&select>0){
				break;
			}else{
				printf("输入无效，请重新选择："); 
				fflush(stdin);
				scanf("%d",&select);
			}
		}
		switch(select){
			case 1:{
				introduce(G);
				break;
			}
			case 2:{
				Show(G);
				break;
			}
			case 3:{
				canGo(GZanc);
				break;
			}
			case 4:{
				introduce(G);
				printf("请输您所在的位置和想要去的位置（编号）：\n");
				scanf("%d->%d",&sta,&end);
				printf("亲爱的懒王：\n%s --> %s的最小长度为：%d\n",G->nodes[sta].name,G->nodes[end].name,dist[sta][end]);
	
				mid=path[sta][end];  // 中间桥梁 
				printf("您可以这样走:   %s",G->nodes[sta].name);   
				while(mid!=end){
					printf(" --> %s",G->nodes[mid].name);
					mid=path[mid][end];  //  不断更新
				}
				printf(" --> %s\n",G->nodes[end].name);
				system("pause");
				break;
			}
			case 5:{
				introduce(G);
				printf("请输您所在的位置和想要去的位置（编号）：\n");
				scanf("%d->%d",&sta,&end);
				
				mid=path_forZanc[sta][end];  // 中间桥梁 
				printf("您可以这样走:   %s",GZanc->nodes[sta].name);   
				time=1; 
				while(mid!=end){
					printf(" --> %s",GZanc->nodes[mid].name);
					mid=path_forZanc[mid][end];  //  不断更新
					time++;
				}
				printf(" --> %s\n",GZanc->nodes[end].name);
				printf ("只需要再走%d个建筑就到了奥！\n",time);
				system("pause"); 
				break;
			}
			
			case 6:{
				printf("再见！");
				return 0;
			}	
		}
	}
	
}
