#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

#define Max 10 

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
	printf("\n\n\n\n");	
}

void SelectSort(List &L){
	for(int i=1;i<=L.length;i++){
		int a=i;
		for(int j = i+1; j<=L.length; j++){
			if(L.data[a] > L.data[j]) a=j;
		}
		if(a!=i){
			L.data[0] = L.data[i];
			L.data[i] = L.data[a];
			L.data[a]=L.data[0];
		} 
	} 
}

int main(){
	List L;
	L.length = 0;
	srand(time(NULL));
	for(int i=1; i<=Max; i++){
		L.data[i] = rand() % 100;
		L.length++;
	}
	print(L);
	
	SelectSort(L);
	print(L);

	return 0;
}
