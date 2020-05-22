#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define Max 9

typedef struct {
	int data[Max+1];
	int length;
}List;

void print(List L){
	int i;
	printf("-------------------------------------------------------------------------------\n");
	for(i=1;i<=L.length;i++)
		printf("%d	",i);
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	for(i=1;i<=L.length;i++)
		printf("%d	",L.data[i]);
	printf("\n");
	printf("\n\n");
}

double log2(double a){
	return log(a)/log(2); 
}

void printT(List T){
	int n=1, i, j;
	int h = log2(T.length);
	printf("-------------------------------------------------------------------------------\n");
	for(i=0;i<=h;i++){
		int ln = pow(2,i);
		//printf("`%d`",ln);
		for(int l=ln; l>0; l--){
			int tabn = pow(2,h-i)-1;
			printf("  ");
			//printf("-%d-",tabn);
			for(int j = tabn; j>0; j--)	printf("  ");
			printf("%d",T.data[n++]);
			if(n>T.length)	break;
			for(int j = tabn; j>0; j--)	printf("  ");
		}
		printf("\n");
	}
} 

void HeapAdjust(List &L,int m,int l){
	L.data[0]=L.data[m];
	for(int i=m*2; i<=l; i=i*2){
		if(i<l && L.data[i+1]>L.data[i]) i++;
		if(L.data[i]<L.data[0]) break;
		L.data[m]=L.data[i];
		m = i;
//		printf("1-------------------------------------------------------------------------------\n");
//		printf("%d\n",i);
//		printT(L);
	}
	L.data[m]=L.data[0];
}

void HeapSort(List &L){
	int i;
	//HeapAdjust(L, 1, L.length);
	for(i=L.length/2; i>0; --i) HeapAdjust(L, i, L.length);
	printT(L);
	for(i=L.length; i>0; --i){
		L.data[0] = L.data[i];
		L.data[i]=L.data[1];
		L.data[1]=L.data[0];
		HeapAdjust(L, 1, i-1);
		//printT(L);	
	}
}

int main(){
	List L;
	L.length=0;
	srand(time(NULL));
	for(int i=1; i<=Max; i++){
		L.data[i] = rand() % 100;
		L.length++;
	}
	printT(L);
//	printf("%d\n",L.length);
//	
	HeapSort(L);
//	
	printT(L);
//	
	return 0;
}
