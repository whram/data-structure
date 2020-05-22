#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

#define Max 11

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

void Adjust(List &L, int m, int l){
	L.data[0] = L.data[m];
	for(int i = m*2; i<=l; i++){
		if(i<l && L.data[i]<L.data[i+1]) i++;
		if(L.data[i]<L.data[0]) break;
		L.data[m] = L.data[i];
		m = i;
	}
	L.data[m] = L.data[0];
}

void Sort(List &L){
	bool flag;
	for(int i = 1; i<=L.length; i++){
		flag = false;
		for(int j = 1; j<=L.length-i; j++){
			if(L.data[j]>L.data[j+1]){
				L.data[0] = L.data[j];
				L.data[j] = L.data[j+1];
				L.data[j+1] = L.data[0];
				flag = true;
			}
		}
		if(flag==false) break;
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
	Sort(L);
	print(L);

	return 0;
}
