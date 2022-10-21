#include<stdio.h>
#include<stdlib.h>
#define Max 1000
struct people{
	int num;
	char Name[Max];
	int preNum;
}pe[Max];
int outQuee();
int Head=0;//队首 
int Tail=-1;//队尾 
int L=0;//队长 
int accNum=0;//实际号码
int bankSta=1;//上班 
int sta=1;//要排队 
void Headline(){
	printf("--------------------------------------------\n");
	printf("              银行叫号系统                  \n");
	printf("--------------------------------------------\n");
}
int inQuee(){
	if(!bankSta) {
		printf("已经下班！");
		system("pause");
		return 0; 
	}
	system("cls");
	Headline();
	printf("                  叫号                      \n");
	L++;
	accNum++;
	Tail=(Tail+1)%Max;
	printf("请输入名字：");
	scanf("%s",&pe[Tail].Name);
	pe[Tail].num=accNum;
	pe[Tail].preNum=Tail-Head;
	printf("%s叫号成功，您的号码为%d，您前面还有%d人。",pe[Tail].Name,pe[Tail].num,pe[Tail].preNum);
	system("pause");
	if(!sta){
		outQuee();
		system("pause");
	}
	return 1;
}
int outQuee(){
	if(!bankSta) {
		printf("已经下班！");
		system("pause");
		return 0; 
	}
	system("cls");
	Headline();
	printf("                 办理业务                    \n");
	if(L==0){
		printf("当前无人排队！\n");
		return 0;
	}
	printf("请%d号顾客到窗口办理业务",pe[Head].num);
	L--;
	Head=(Head+1)%Max;
	return 1;
}
int showQee(){
	system("cls");
	Headline();
	printf("                  展示                      \n");
	printf("				当前队列长度：%d                \n",L); 
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
		printf("已经下班！");
		system("pause");
		return 0; 
	}
	if(sta){
		sta=0;
		printf("修改成功，全部出队！\n"); 
		int lenZanc=L; 
		for(int i=0;i<lenZanc;i++){
			outQuee();
			system("pause");
		}
	}else{
		sta=1;
		printf("修改成功，目前需要排队\n"); 
	}
	system("pause");
	
}
int bank(){
	if(bankSta){
		bankSta=0;
		printf("下班咯！");
		return 1; 
	}else{
		bankSta=1;
		printf("上班咯！");
		return 1; 
	}
} 
int Map(){
	while(1){
		system("cls");
		Headline();
		printf("1.叫号\n"); 
		printf("2.请队首办理业务\n");
		printf("3.队列展示\n");
		printf("4.修改排队状态\n");
		printf("5.修改上下班状态\n");
		printf("6.退出系统\n\n\n\n\n");
		printf("			当前银行状态：%d（1：上班 0：下班)\n			当前队长：%d\n			当前排队状态：%d  （1：需要排队 0：无需排队）\n",bankSta,L,sta);
		printf("请选择相应的功能（1-5）:");
		fflush(stdin);
		int select;
		scanf("%d",&select);
		while(1){
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
				printf("再见！");
				return 0;
			}	
		}
	}
}
int main(){
	Map(); 
}
