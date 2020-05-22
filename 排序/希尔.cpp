#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize+1];
	int length=0;
}Seqlist;

void print(Seqlist L){
	int i;
	printf("-------------------------------------------------------------------------------\n");
	for(i=1;i<=L.length;i++)
		printf("%d	",i);
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	for(i=1;i<=L.length;i++)
		printf("%d	",L.data[i]);
	printf("\n\n\n\n");	
}

void SellSort(Seqlist &L,int &cont){
	int n, i, j;
	for(n = L.length/2; n>=1; n=n/2){
		for(i=n+1;i<=L.length;i++){
			print(L);
			if(L.data[i] < L.data[i-n]){
				L.data[0] = L.data[i];
				for(j = i-n; j>0 && L.data[j]>L.data[0]; j-=n)
					L.data[j+n] = L.data[j];
					cont++;
				L.data[j+n]=L.data[0];
				printf("sign:%d\n", L.data[j]);
			}
		}
		//print(L);
	}
}

int main(){
	Seqlist L1,L2;
	int i;
	srand(time(NULL));
	for(i = 1;i<=MaxSize;i++){
		L1.data[i] = rand() % 100;
		//L1.data[i] = MaxSize-i;
		L1.length++;
	}
	print(L1);
	L2=L1;
	
//	printf("----cut----\n");
	int cont;
	SellSort(L1,cont);
	print(L1);
	printf("cont:%d\n",cont);
	printf("----cut----\n");

//	print(L2);
//	Pop(L2,cont);
//	printf("----cut----\n");
//	print(L2);
//	printf("cont:%d\n",cont);

}
