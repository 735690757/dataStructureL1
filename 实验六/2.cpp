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
int qui(int left,int right){
	int i,j;
	i=left;
	j=right;
	stuQuee[0]=stuQuee[left];
	while(i<j){
		while(i<j&&stuQuee[0].Score<stuQuee[j].Score){
			j--;
		}
		if(i<j){
			stuQuee[i]=stuQuee[j];
			i++;
		}
		while(i<j&&stuQuee[i].Score<stuQuee[0].Score){
			i++;
		}
		if(i<j){
			stuQuee[j]=stuQuee[i];
			j--;
		}
	}
	stuQuee[i]=stuQuee[0];
	if(left<i){
		qui(left,j-1);
	}
	if(i<right){
		qui(j+1,right);
	}
	return 0;
	
}
int main(){
	srand((unsigned int)time(0));
	int n;
	printf("请输入学生的数量：");
	scanf("%d",&n);
	setUp_Quee(n);
	show_Quee(n);
	qui(0,n);
	printf("展示：\n");
	ans(n);
} 
