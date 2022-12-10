#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxDL 50
#define MaxPN 500
int People=0;
struct people{
	char Name[MaxDL];//名字 
	char pNumber[MaxDL];//电话号码 
	
}pe[MaxPN];//结构体数组 
void Headline(){
	printf("--------------------------------------------\n");
	printf("               通讯录系统                   \n");
	printf("--------------------------------------------\n");
}
int addPe();	//增 
int delPe();	//删 
int modifyPe();	//改 
int queryPe();	//查 
int addPe(){		//增
	system("cls");
	Headline();
	People++;
	printf("                  添加                      \n");
	printf("请输入联系人姓名：\n");
	scanf("%s",pe[People].Name);
	printf("请输入联系人手机号码：\n");
	scanf("%s",pe[People].pNumber);
	printf("添加成功！\n"); 
	system("pause");
}
int delPe(){	//删 
	Headline();
	printf("                  删除                      \n");
	if(People==0){
		printf("没有什么可以删除的......\n");
		system("pause");
		return 0; 
	} 
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("请输入要删除的联系人编号");
	int select;
	while(1){
		fflush(stdin);//C语言清空输入缓冲区函数(这里解决了scanf函数被注入非法字符而失效的问题) 
		scanf("%d",&select);
		if(select<=People&&select>0){
			break;
		}else{
			printf("没有这个编号！请重新输入：\n");
		}
	}
	for(int i=select;i<People;i++){		//整体前移 
		strcpy(pe[i].Name,pe[i+1].Name);
		strcpy(pe[i].pNumber,pe[i+1].pNumber);	
	}
	People--;
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	}
	printf("铲掉铲掉！！");
	system("pause");
}
int modifyPe(){//改 
	Headline();
	if(People==0){
		printf("没有什么可以修改的......\n");
		system("pause");
		return 0; 
	} 
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("                  修改                      \n");
	printf("请输入需要修改联系人的编号：\n");
	int num,select;
	while(1){
		fflush(stdin);
		scanf("%d",&num);
		if(num<=People&&num>0){
			break;
		}else{
			printf("没有这个编号！请重新输入：\n");
		}
	}
	while(1){
		int flag=0;
		printf("请选择:\n1.修改姓名\n2.修改电话号码：\n");
		fflush(stdin);//C语言清空输入缓冲区函数(这里解决了scanf函数被注入非法字符而失效的问题) 
		scanf("%d",&select);
		switch(select){
			case 1:{
				printf("请输入新姓名：\n");
				scanf("%s",&pe[num].Name);
				flag=1;
				break;
			}
			case 2:{
				printf("请输入新电话号码：\n");
				scanf("%s",&pe[num].pNumber);
				flag=1;
				break;
			}
			default:{
				printf("选择错误，请重新选择！\n");
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	 
	printf("害嗨害，改好了奥！\n");
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	system("pause");
}
int queryPe(){//查 
	system("cls");
	Headline();
	printf("                  查看                      \n");
	printf("序号		");
	printf("姓名		");
	printf("电话号码		\n");
	for(int i=1;i<=People;i++){
		printf("%d		",i);
		printf("%s		",pe[i].Name);
		printf("%s		\n",pe[i].pNumber);
	} 
	printf("到底啦！！嘻嘻\n");
	system("pause");
}
int queryPe_I_Number(){
	system("cls");
	Headline();
	printf("              按手机号查询                   \n");
	char pNZanc[MaxDL];
	scanf("%s",&pNZanc);
	printf("请输入手机号");
	for(int i=1;i<=People;i++){
		if(strcmp(pNZanc,pe[i].pNumber) == 0){
			printf("已经找到了！");
			return i; 
		}
	}
	system("pause");
}
int queryPe_I_Name(){
	system("cls");
	Headline();
	printf("              按姓名号查询                   \n");
	char pNZanc[MaxDL];
	printf("请输入姓名：\n"); 
	scanf("%s",&pNZanc);
	for(int i=1;i<=People;i++){
		if(strcmp(pNZanc,pe[i].Name) == 0){
			printf("已经找到了！\n");
			return i; 
		}
		
	}
	printf("没找到！！\n");
	system("pause");
	return -1;
}
int queryguide_I_Number(){
	int sel,i;
	printf("\n1.按手机号查询\n2.按姓名查询\n") ;
	printf("请输入：\n");
	fflush(stdin);
	scanf("%d",&sel);
	while(1){
		
			if(i<3&&i>=1){
				break;
			}else{
				printf("输入无效，请重新选择："); 
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
		printf("1.添加联系人\n"); 
		printf("2.删除联系人\n");
		printf("3.修改联系人信息\n");
		printf("4.所有联系人展示\n");
		printf("5.按手机号/姓名查询\n");
		printf("6.退出系统\n\n\n\n\n");
		printf("请选择相应的功能（1-5）:");
		int select;
		scanf("%d",&select);
		while(1){
			if(select<=7&&select>0){
				break;
			}else{
				printf("输入无效，请重新选择："); 
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
				printf("再见！");
				return 0;
			}	
		}
	}
}
int main(){
	Map();
	return 0;
}
