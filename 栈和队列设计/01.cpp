#include<stdio.h>
#include<stdlib.h>
#define Max 1000
struct people{
	int num;
	char Name[Max];
	int preNum;
}pe[Max];
int outQuee();
int Head=0;//���� 
int Tail=-1;//��β 
int L=0;//�ӳ� 
int accNum=0;//ʵ�ʺ���
int bankSta=1;//�ϰ� 
int sta=1;//Ҫ�Ŷ� 
void Headline(){
	printf("--------------------------------------------\n");
	printf("              ���нк�ϵͳ                  \n");
	printf("--------------------------------------------\n");
}
int inQuee(){
	if(!bankSta) {
		printf("�Ѿ��°࣡");
		system("pause");
		return 0; 
	}
	system("cls");
	Headline();
	printf("                  �к�                      \n");
	L++;
	accNum++;
	Tail=(Tail+1)%Max;
	printf("���������֣�");
	scanf("%s",&pe[Tail].Name);
	pe[Tail].num=accNum;
	pe[Tail].preNum=Tail-Head;
	printf("%s�кųɹ������ĺ���Ϊ%d����ǰ�滹��%d�ˡ�",pe[Tail].Name,pe[Tail].num,pe[Tail].preNum);
	system("pause");
	if(!sta){
		outQuee();
		system("pause");
	}
	return 1;
}
int outQuee(){
	if(!bankSta) {
		printf("�Ѿ��°࣡");
		system("pause");
		return 0; 
	}
	system("cls");
	Headline();
	printf("                 ����ҵ��                    \n");
	if(L==0){
		printf("��ǰ�����Ŷӣ�\n");
		return 0;
	}
	printf("��%d�Ź˿͵����ڰ���ҵ��",pe[Head].num);
	L--;
	Head=(Head+1)%Max;
	return 1;
}
int showQee(){
	system("cls");
	Headline();
	printf("                  չʾ                      \n");
	printf("				��ǰ���г��ȣ�%d                \n",L); 
	int p=Head;
	for(int i=0;i<L;i++){
		printf("	%s",pe[(p)%Max].Name);
		printf("	%d",pe[(p)%Max].num);
		printf("	%d\n",pe[(p)%Max].preNum);
		p++;
	}
	system("pause");
	return 1; 
}
int chSta(){
	if(!bankSta) {
		printf("�Ѿ��°࣡");
		system("pause");
		return 0; 
	}
	if(sta){
		sta=0;
		printf("�޸ĳɹ���ȫ�����ӣ�\n"); 
		int lenZanc=L; 
		for(int i=0;i<lenZanc;i++){
			outQuee();
			system("pause");
		}
	}else{
		sta=1;
		printf("�޸ĳɹ���Ŀǰ��Ҫ�Ŷ�\n"); 
	}
	system("pause");
	
}
int bank(){
	if(bankSta){
		bankSta=0;
		printf("�°࿩��");
		return 1; 
	}else{
		bankSta=1;
		printf("�ϰ࿩��");
		return 1; 
	}
} 
int Map(){
	while(1){
		system("cls");
		Headline();
		printf("1.�к�\n"); 
		printf("2.����װ���ҵ��\n");
		printf("3.����չʾ\n");
		printf("4.�޸��Ŷ�״̬\n");
		printf("5.�޸����°�״̬\n");
		printf("6.�˳�ϵͳ\n\n\n\n\n");
		printf("			��ǰ����״̬��%d��1���ϰ� 0���°�)\n			��ǰ�ӳ���%d\n			��ǰ�Ŷ�״̬��%d  ��1����Ҫ�Ŷ� 0�������Ŷӣ�\n",bankSta,L,sta);
		printf("��ѡ����Ӧ�Ĺ��ܣ�1-5��:");
		fflush(stdin);
		int select;
		scanf("%d",&select);
		while(1){
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
				inQuee();
				break;
			}
			case 2:{
				outQuee();
				system("pause");
				break;
			}
			case 3:{
				showQee();
				break;
			}
			case 4:{
				chSta();
				break;
			}
			case 5:{
				bank(); 
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
int main(){
	Map(); 
}
