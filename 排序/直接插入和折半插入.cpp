#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Max 6

typedef struct {
	int data[Max];
	int length;
}List;

void print(List L){
	int i;
	printf("-------------------------------------------------------------------------------\n");
	for(i=0;i<L.length;i+=1)
		printf("%d	",i+1);
	printf("\n");
	printf("--------------------------------------------------------------------------------\n");
	for(i=1;i<=L.length;i+=1)
		printf("%d	",L.data[i]);
	printf("\n\n\n\n");	
}

void InsertSort(List &L){
	int i, j;
	for(i = 2; i <= L.length; i++){
		if(L.data[i] < L.data[i-1]){
			L.data[0] = L.data[i];
			L.data[i] = L.data[i-1];
			for(j = i-1; L.data[j]>L.data[0]; j--){
				L.data[j+1] = L.data[j];
			} 
			L.data[j+1] = L.data[0];
		}
	}
}

void BInsertSort(List &L){
	int m,high,low,i;
	for(i = 2;i<=L.length;i++){
		low = 1;
		high = i-1;
		L.data[0] = L.data[i];
		while(low<=high){
			m = (low+high)/2;
			if(L.data[0]<L.data[m]) high = m-1;
			else low = m+1;
		}
		for(int j=i-1; j>=high+1; j--) L.data[j+1]=L.data[j];
		L.data[high+1] = L.data[0];
	}
}

int main(){
	List L;
	L.length = 0;
	srand(time(NULL));
	for(int i=1; i<Max; i++){
		L.data[i] = rand() % 100;
		L.length++;
	}
	print(L);

	InsertSort(L);
	print(L);
	
	return 0;
}
