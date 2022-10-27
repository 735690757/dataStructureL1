//¹þ·òÂü±àÂë 
#include <stdio.h>
#include <cstdlib>
#include <malloc.h>
#include <string.h>
#define M 100
typedef struct{
	char data[1024];
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
typedef char **HuffmanCode;
void CreateHT(HTNode ht[], int n){
	char *str[] = {"A","B","C","D","E","F","G","H"};
	int fnum[] = { 5, 25, 4, 7, 9, 12, 30, 8 };
	int i,k;
	int lnode,rnode;
	short min1,min2;
	for (i = 0; i<n; i++){
		strcpy(ht[i].data, str[i]);
		ht[i].weight = fnum[i];
	}
	for (i = 0; i<2 * n - 1; i++){
		ht[i].parent = -1;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}

	for (i = n; i<2 * n - 1; i++){
		min1 = 32767; min2 = 32767;
		lnode = -1; rnode = -1;
		for (k = 0; k < i ; k++){
			if (ht[k].parent == -1){
				
				if (ht[k].weight<min1){
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else{
					if (ht[k].weight<min2){
						min2 = ht[k].weight;
						rnode = k;
					}
				}
			}
		}
		ht[rnode].parent = i;
		ht[lnode].parent = i;
		ht[i].weight = ht[rnode].weight + ht[lnode].weight;
		if (lnode>rnode){
			ht[i].lchild = lnode;
			ht[i].rchild = rnode;
		}
		else{
			ht[i].lchild = rnode;
			ht[i].rchild = lnode;
		}
	}
}
void CreateHCode(HTNode ht[], HuffmanCode hcd, int n){
	int i, f, c, temp;
	char *hc;
	for (i = 0; i<n; i++){
		hc = (char *)malloc(n*sizeof(char));
		hc[n] = '\0';
		temp = n - 1;
		c = i;
		f = ht[i].parent;
		while (f != -1){
			if (ht[f].lchild == c)
				hc[temp--] = '0';
			else
				hc[temp--] = '1';
			c = f;
			f = ht[f].parent;
		}
		hcd[i] = (char*)malloc((n - temp)*sizeof(char));
		strcpy(hcd[i], hc + temp + 1);
	}
}
void DispHCode(HTNode ht[], HuffmanCode hcd, int n){
	int i;
	int sum = 0, j;
	printf("¹þ·òÂü±àÂë:\n");
	for (i = 0; i<n; i++){
		j = 0;
		printf("%s:\t", ht[i].data);
		while (hcd[i][j] != '\0'){
			printf("%c", hcd[i][j]);
			j++;
		}
		sum += ht[i].weight*j;
		printf("\n");
	}
}
int main(){
	int n = 8;
	HTNode ht[M];
	HuffmanCode hcd;
	hcd = (HuffmanCode)malloc((2 * n)*sizeof(char*));
	CreateHT(ht, n);
	CreateHCode(ht, hcd, n);
	DispHCode(ht, hcd, n);
	printf("\n");
	system("pause");
	return 0;
}
