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

void Bub(List &L){
	bool flag;
	for(int i = 1; i<=L.length; i++){
		flag = false;
		for(int j=1; j<=L.length-i; j++){
			if(L.data[j]>L.data[j+1]){
				L.data[0] = L.data[j];
				L.data[j] = L.data[j+1];
				L.data[j+1] = L.data[0];
				flag = true;
			}
		}
		if(flag == false) break;
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
	
	Bub(L);
	print(L);

	return 0;
}
