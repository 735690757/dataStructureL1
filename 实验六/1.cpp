#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 10000
struct Stu{
	char Name;
	int Score;
}stuQuee[Max];
int setUp_Quee(int n){
	for(int i=1;i<=n;i++){
		stuQuee[i].Name='A'+i;
		stuQuee[i].Score=rand()%100+1;
	}
}
void show_Quee(int n){
	for(int i=n;i>=1;i--){
		printf("%c	",stuQuee[i].Name);
		printf("%d\n",stuQuee[i].Score);
	}
}
void ans(int n){
	int top=1;
	for(int i=n;i>=1;i--){
		printf("%d	",top);
		printf("%c	",stuQuee[i].Name);
		printf("%d\n",stuQuee[i].Score);
		if(stuQuee[i].Score==stuQuee[i-1].Score){
			
		}else{
			top++;
		}
	}
}
void insert(int n){
	int j;
	for(int i=2;i<=n;i++){
		if(stuQuee[i].Score<stuQuee[i-1].Score){
			stuQuee[0]=stuQuee[i];
			for(j=i-1;stuQuee[0].Score<stuQuee[j].Score;j--){
				stuQuee[j+1]=stuQuee[j];
			}
			stuQuee[j+1]=stuQuee[0];
		}
	}
}
int main(){
	srand((unsigned int)time(0));
	int n;
	printf("请输入学生的数量：");
	scanf("%d",&n);
	setUp_Quee(n);
	show_Quee(n);
	insert(n);
	printf("展示：\n");
	ans(n);
} 
