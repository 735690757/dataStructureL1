#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ṹ����Ƽ���궨��淶���������뷶������ͬ���
//��������������������Ʊ�д 
#define V 11
#define E 15
//15���ߡ�11���ڵ� 
#define maxSize 1000
#define maxWeight 8888					//���ɴ� 
typedef struct Node{					//ѧУ�����ڵ���Ϣ 
	char name[maxSize];  				//�������� 
	int X; 								//���� 
	char introduction[maxSize*10];   	//������
}Node;
typedef struct Graph{			//ͼ 
 	Node nodes[12];   			//ʮһ������ 
 	int Weight[20][20];   		//Ȩֵ
 	int vnum;					//������
	int edge;    				//���� 
}Graph;
//�Ӻ���ͳһ�淶���£� 
int CreateGraph(Graph* G);				//��ͼ��������Ȩ����Ϣ����			**������** 
int CreateGraph_forZanc(Graph* G);		//��ͼ���ɴ��Ϣ����				**������**
Graph* Find(Graph *G);					//��ͼ��������Ȩ���ĸ��������㷨	**������**
Graph* Find_forZanc(Graph *G);			//��ͼ���ɴ�ĸ��������㷨		**������**
void Headline();						//��פ�̱���						**�����**
void Headline_Long();					//��פ������						**�����**
void introduce(Graph *G);				//�ڵ���Ϣ����						**�����**
void Show(Graph *G);					//�ڵ��ڽӾ���չʾ					**���챦** 
void canGo(Graph* G);					//һ��ֱ��ڵ���Ϣչʾ				**���챦** 
										//main()							**������**
int CreateGraph(Graph* G){//**������** 
	G->edge=E;	//15����
	G->vnum=V;	//11������
	for(int i=1;i<=G->vnum;i++){		//��ʼ���ڵ���� 
		G->nodes[i].X=i;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int w=1;w<=G->vnum;w++){
			G->Weight[i][w]=maxWeight;			//��ʼ���ڵ�ȨֵΪ���ɴ�:"maxWeight" 
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

int CreateGraph_forZanc(Graph* G){//**������** 
	G->edge=E;	//15����
	G->vnum=V;	//11������
	for(int i=1;i<=G->vnum;i++){		//��ʼ���ڵ���� 
		G->nodes[i].X=i;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int w=1;w<=G->vnum;w++){
			G->Weight[i][w]=maxWeight;			//��ʼ���ڵ�ȨֵΪ���ɴ�:"maxWeight" 
		}
	} 
	FILE *fp;
	int u,i,w; 
	fp = fopen("Weight.txt", "r");
	for(int i=1;i<=E;i++){
		fscanf(fp, "%d %d %d", &u,&i,&w);
		G->Weight[u][i]=G->Weight[i][u]=1;		//�ɴ� 
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
int dist[maxSize][maxSize];				//������·������ ��ʼΪͼ���ڽӾ��� 
int path[maxSize][maxSize];				//��Ŵ�Vi��Vj�����·�� ��ʼΪpath[i][j]="ViVj" 
Graph* Find(Graph *G){	//**������**		
	for(int p=1;p<=G->vnum;p++){		//�Լ����Լ���ȫ�ɴ���Ϊ0 
		G->Weight[p][p]=0;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int j=1;j<=G->vnum;j++){
			dist[i][j]=G->Weight[i][j]; 	//��������·��,��ʼ��Ϊ�����Ȩֵ 
			path[i][j]=j;   				//���·������һ����  
		}
	}
	//���������㷨
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
int dist_forZanc[maxSize][maxSize];				//������·������ ��ʼΪͼ���ڽӾ��� 
int path_forZanc[maxSize][maxSize];	
Graph* Find_forZanc(Graph *G){	//**������**		
	for(int p=1;p<=G->vnum;p++){		//�Լ����Լ���ȫ�ɴ���Ϊ0 
		G->Weight[p][p]=0;
	}
	for(int i=1;i<=G->vnum;i++){
		for(int j=1;j<=G->vnum;j++){
			dist_forZanc[i][j]=G->Weight[i][j]; 	//��������·��,��ʼ��Ϊ�����Ȩֵ 
			path_forZanc[i][j]=j;   				//���·������һ���� 
		}
	}
	//���������㷨
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
void Headline(){//**�����** 
	printf("--------------------------------------------\n");
	printf("               У԰����ϵͳ                 \n");
	printf("--------------------------------------------\n");
}
void Headline_Long(){//**�����** 
	printf("---------------------------------------------------------------------------------------------------------\n\n");
	printf("               					У԰����ϵͳ								                 \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
}
void introduce(Graph *G){//**�����** 
//���� 
	system("cls");		//cmd���� 
	Headline();
	printf("���	����		����\n"); 
	for(int i=1;i<=G->vnum;i++){
		printf("%d	%s		%s\n",G->nodes[i].X,G->nodes[i].name,G->nodes[i].introduction);
	}
	system("pause");	//cmd��ͣ 
}
void Show(Graph *G){//**���챦** 
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
				printf("��	");
			}else{
				printf("%d	",G->Weight[i][j]);
			}
			
		}
		printf("	|\n");
	}
	printf("\n\n\n\n	****	��Ϊ����ֱ�	****	\n\n\n\n");
	system("pause");
}
void canGo(Graph* G){//**���챦** 
	introduce(G);
	printf("�������أ�\n�����룺");
	int loc;
	scanf("%d",&loc);
	printf("�����ֱ�����µص㣺\n"); 
	for(int i=1;i<=E;i++){
			if(G->Weight[loc][i]==1){
				printf("%s\n",G->nodes[i].name);
		}
	}
	system("pause");
}
int main(){//**������** 
	int time;		//��Ҫ���ߵĴ��� 
	Graph *G;		//����Ȩֵͼ 
	Graph *GZanc;	//�ɴ�ͼ
	G=(Graph*)malloc(sizeof(Graph));
	GZanc=(Graph*)malloc(sizeof(Graph));
	
	for(int q=1;q<=E;q++){
		for(int w=1;w<=E;w++){
 			dist[q][w]=maxWeight;    //��ʼ��
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
		printf("1.У԰�ڵ���ܣ�\n"); 
		printf("2.��ͼ�ڽӾ���չʾ��\n");
		printf("3.�����������ߣ�\n"); 
		printf("4.��Ҫ������ѡ�ҾͶ��ˣ�(�����������һЩ·�Ļ�)\n");
		printf("5.��Ҫ������ѡ����ף�(������뾭��һЩ�����Ļ�)\n");
		printf("6.�˳�ϵͳ\n\n\n\n\n");
		printf("				�鳤��������\n				��Ա������������������챦\n				лл�ɰ�����Ա�ǣ���\n"); 
		printf("��ѡ����Ӧ�Ĺ��ܣ�1-5��:");
		int select;
		scanf("%d",&select);
		while(1){
			if(select<=6&&select>0){
				break;
			}else{
				printf("������Ч��������ѡ��"); 
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
				printf("���������ڵ�λ�ú���Ҫȥ��λ�ã���ţ���\n");
				scanf("%d->%d",&sta,&end);
				printf("�װ���������\n%s --> %s����С����Ϊ��%d\n",G->nodes[sta].name,G->nodes[end].name,dist[sta][end]);
	
				mid=path[sta][end];  // �м����� 
				printf("������������:   %s",G->nodes[sta].name);   
				while(mid!=end){
					printf(" --> %s",G->nodes[mid].name);
					mid=path[mid][end];  //  ���ϸ���
				}
				printf(" --> %s\n",G->nodes[end].name);
				system("pause");
				break;
			}
			case 5:{
				introduce(G);
				printf("���������ڵ�λ�ú���Ҫȥ��λ�ã���ţ���\n");
				scanf("%d->%d",&sta,&end);
				
				mid=path_forZanc[sta][end];  // �м����� 
				printf("������������:   %s",GZanc->nodes[sta].name);   
				time=1; 
				while(mid!=end){
					printf(" --> %s",GZanc->nodes[mid].name);
					mid=path_forZanc[mid][end];  //  ���ϸ���
					time++;
				}
				printf(" --> %s\n",GZanc->nodes[end].name);
				printf ("ֻ��Ҫ����%d�������͵��˰£�\n",time);
				system("pause"); 
				break;
			}
			
			case 6:{
				printf("�ټ���");
				return 0;
			}	
		}
	}
	
}
