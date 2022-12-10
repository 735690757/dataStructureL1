#include<stdio.h>
 
#include<stdlib.h>
#include<windows.h>
#define MaxV 500
#define NVn 19//g->n=19;
#define NVe 24//g->e=24;
typedef struct{
	int no;//��� 
	char info[MaxV];//��� 
	char infoX[MaxV];
}VertexType;
typedef struct{
	int edges[MaxV][MaxV];//�ڽӾ��� 
	int n,e;//���㣬�� 
	VertexType vexs[MaxV];
}MGraph;
void Headline(){
	printf("--------------------------------------------\n");
	printf("              ��������ϵͳ                  \n");
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
int Prim(MGraph *M){//Prim�㷨 
	Headline();
	int adjvex[MaxV],lowcost[MaxV];//�ֱ�Ϊ�ڽӵ�����СȨֵ 
	lowcost[MaxV]=0;
	int sum=0;
	int zancMinex=8000; 
	int zancFlag=0;//��־�����ڸ�ֵ 
	int zancMinerc=0;
//�Ӵ˿�ʼ 
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
//���˽�������Ϊ����չʾ�����漰�㷨���� 
		for(int j=0;j<M->n;j++){
			if(lowcost[j]<zancMinex&&lowcost[j]!=0){
			//����ҵ�һ����ԭ��Ȩֵ��С����ֵ����ô�Ͷ�����и��µ��� 
				zancFlag=j;//���±�־ 
				zancMinerc=lowcost[j];//������СȨֵ 
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
		zancMinex=8000;//������Ϊα���� 
		sum+=zancMinerc;//Ȩֵ��ͣ�������� 
		printf("Ŀǰ���ȣ�%d\n",sum);
	}
	printf("ȫ����С��ۣ�%d",sum);
	return sum;
	
}
int vist[MaxV]={0};//������Ƿ񱻷��ʹ�
void Rec(){
	Headline();
	windows_cmd_support_utf8();
	printf("Recommended tour routes are as follows:");
}
int p=0; 
int sta=0;
int DFS(MGraph *M,int v){//������ȱ��� 
	
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
	printf("\n�����԰��Ϣ:\n");
	for(i=0;i<g->n;i++){
		printf("	%d	|	",i);
		for(j=0;j<g->n;j++){
			k++;
			if(g->edges[i][j]>7000){
				printf("��  ");	
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
		printf("1.��԰�������\n"); 
		printf("2.��԰�ڽӾ���չʾ\n");
		printf("3.ȫ����ѹܵ�ά��·��\n");
		printf("4.������������ĳһ�ڵ��·������\n");
		printf("5.�˳�ϵͳ\n\n\n\n\n");
		printf("��ѡ����Ӧ�Ĺ��ܣ�1-5��:");
		int select;
		scanf("%d",&select);
		while(1){
			windows_cmd_support_GBK();
			if(select<=5&&select>0){
				break;
			}else{
				printf("������Ч��������ѡ��"); 
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
				printf("�ټ���");
				return 0;
			}	
		}
	}
} 
