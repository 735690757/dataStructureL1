#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxDL 50
#define MaxPN 500
int People=0;
struct people{
	char Name[MaxDL];//���� 
	char pNumber[MaxDL];//�绰���� 
	
}pe[MaxPN];//�ṹ������ 
void Headline(){
	printf("--------------------------------------------\n");
	printf("               ͨѶ¼ϵͳ                   \n");
	printf("--------------------------------------------\n");
}
int addPe();	//�� 
int delPe();	//ɾ 
int modifyPe();	//�� 
int queryPe();	//�� 
int addPe(){		//��
	system("cls");
	Headline();
	People++;
	printf("                  ���                      \n");
	printf("��������ϵ��������\n");
	scanf("%s",pe[People].Name);
	printf("��������ϵ���ֻ����룺\n");
	scanf("%s",pe[People].pNumber);
	printf("��ӳɹ���\n"); 
	system("pause");
}
int delPe(){	//ɾ 
	Headline();
	printf("                  ɾ��                      \n");
	if(People==0){
		printf("û��ʲô����ɾ����......\n");
		system("pause");
		return 0; 
	} 
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("������Ҫɾ������ϵ�˱��");
	int select;
	while(1){
		fflush(stdin);//C����������뻺��������(��������scanf������ע��Ƿ��ַ���ʧЧ������) 
		scanf("%d",&select);
		if(select<=People&&select>0){
			break;
		}else{
			printf("û�������ţ����������룺\n");
		}
	}
	for(int i=select;i<People;i++){		//����ǰ�� 
		strcpy(pe[i].Name,pe[i+1].Name);
		strcpy(pe[i].pNumber,pe[i+1].pNumber);	
	}
	People--;
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	}
	printf("������������");
	system("pause");
}
int modifyPe(){//�� 
	Headline();
	if(People==0){
		printf("û��ʲô�����޸ĵ�......\n");
		system("pause");
		return 0; 
	} 
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("                  �޸�                      \n");
	printf("��������Ҫ�޸���ϵ�˵ı�ţ�\n");
	int num,select;
	while(1){
		fflush(stdin);
		scanf("%d",&num);
		if(num<=People&&num>0){
			break;
		}else{
			printf("û�������ţ����������룺\n");
		}
	}
	while(1){
		int flag=0;
		printf("��ѡ��:\n1.�޸�����\n2.�޸ĵ绰���룺\n");
		fflush(stdin);//C����������뻺��������(��������scanf������ע��Ƿ��ַ���ʧЧ������) 
		scanf("%d",&select);
		switch(select){
			case 1:{
				printf("��������������\n");
				scanf("%s",&pe[num].Name);
				flag=1;
				break;
			}
			case 2:{
				printf("�������µ绰���룺\n");
				scanf("%s",&pe[num].pNumber);
				flag=1;
				break;
			}
			default:{
				printf("ѡ�����������ѡ��\n");
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	 
	printf("���˺����ĺ��˰£�\n");
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	system("pause");
}
int queryPe(){//�� 
	system("cls");
	Headline();
	printf("                  �鿴                      \n");
	printf("���		");
	printf("����		");
	printf("�绰����		\n");
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("��������������\n");
	system("pause");
}
int queryPe_I_Number(){
	system("cls");
	Headline();
	printf("              ���ֻ��Ų�ѯ                   \n");
	char pNZanc[MaxDL];
	scanf("%s",&pNZanc);
	printf("�������ֻ���");
	for(int i=1;i<=People;i++){
		if(strcmp(pNZanc,pe[i].pNumber) == 0){
			printf("�Ѿ��ҵ��ˣ�");
			return i; 
		}
	}
	system("pause");
}
int queryPe_I_Name(){
	system("cls");
	Headline();
	printf("              �������Ų�ѯ                   \n");
	char pNZanc[MaxDL];
	printf("������������\n"); 
	scanf("%s",&pNZanc);
	for(int i=1;i<=People;i++){
		if(strcmp(pNZanc,pe[i].Name) == 0){
			printf("�Ѿ��ҵ��ˣ�\n");
			return i; 
		}
		
	}
	printf("û�ҵ�����\n");
	system("pause");
	return -1;
}
int queryguide_I_Number(){
	int sel,i;
	printf("\n1.���ֻ��Ų�ѯ\n2.��������ѯ\n") ;
	printf("�����룺\n");
	fflush(stdin);
	scanf("%d",&sel);
	while(1){
		
			if(i<3&&i>=1){
				break;
			}else{
				printf("������Ч��������ѡ��"); 
				fflush(stdin);
				scanf("%d",&i);
			}
		}
	if(sel==1){
		i=queryPe_I_Number();	
	}else{
		i=queryPe_I_Name();
	}
	if(i==-1){
		return 0;
	}
	printf("%d		",i);
	printf("%s		",pe[i].Name);
	printf("%s		\n",pe[i].pNumber);
	system("pause");
	return 1;
}
int Map(){
	while(1){
		system("cls");
		Headline();
		printf("1.�����ϵ��\n"); 
		printf("2.ɾ����ϵ��\n");
		printf("3.�޸���ϵ����Ϣ\n");
		printf("4.������ϵ��չʾ\n");
		printf("5.���ֻ���/������ѯ\n");
		printf("6.�˳�ϵͳ\n\n\n\n\n");
		printf("��ѡ����Ӧ�Ĺ��ܣ�1-5��:");
		int select;
		scanf("%d",&select);
		while(1){
			if(select<=7&&select>0){
				break;
			}else{
				printf("������Ч��������ѡ��"); 
				fflush(stdin);
				scanf("%d",&select);
			}
		}
		switch(select){
			case 1:{
				addPe();
				break;
			}
			case 2:{
				delPe();
				break;
			}
			case 3:{
				modifyPe();
				break;
			}
			case 4:{
				queryPe();
				break;
			}
			case 5:{
				queryguide_I_Number();
				break;
			} 
			case 6:{
				printf("�ټ���");
				return 0;
			}	
		}
	}
}
int main(){
	Map();
	return 0;
}
