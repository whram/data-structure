#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Max 10

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

void Create(List &L){
	srand(time(NULL));
	for(int i=1; i<Max; i++){
		L.data[i] = rand() % 100;
		L.length++;
	}
}

void Bub(List &L){
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

void Select(List &L){
	int temp;
	for(int i=1; i<=L.length; i++){
		L.data[0] = L.data[i];
		temp = i;
		for(int j=i; j<=L.length; j++){
			if(L.data[j]<L.data[0]){
				L.data[i] = L.data[j];
				temp = j;
			}
		}
		L.data[temp] = L.data[0];
	}
}

int Part(List &L, int low, int high){
	int m;
	L.data[0] = L.data[low];
	while(low<=high){
		while(low<high && L.data[high]>=L.data[0]) high--;
		L.data[low] = L.data[high];
		while(L.data[low] <= L.data[0]) low++;
		L.data[high] = L.data[low];
	}
	m = low;
	L.data[low] = L.data[0];
	return m;
}

void Qsort(List &L, int low, int high){
	int m = Part(L,low,high);
	Qsort(L,m+1,high);
	Qsort(L,low,m-1);
}

void BiInster(List &L){
	int low, high, m;
	for(int i = 2; i<=L.length; i++){
		low = 1; high = i; m = (low+high)/2;
		L.data[0] = L.data[i];
		while(low<=high){
			if(L.data[m]>L.data[0]) high = m-1;
			else low = m+1;
		}
		for(int j = i-1; j>0; j--) L.data[j+1] = L.data[j];
		L.data[low] = L.data[0];
	}
}

void Sell(List &L){
	int j;
	for(int d = L.length/2; d<0; d = d/2){
		for(int i = d+1; i<=L.length; i++){
			L.data[0] = L.data[i];
			if(L.data[i]<L.data[i-d]){
				for(j = i-d; j>0 && L.data[j] > L.data[0]; j+=d) L.data[j+d] = L.data[j];
				L.data[j+d] = L.data[0];
			}
		}
	}
}

void Adjust(List &L, int n, int l){
	L.data[0] = L.data[n];
	for(int i=n*2; i<=l; i=i*2){
		if(i+1<=l && L.data[i]<L.data[i+1]) i++;
		if(L.data[i] < L.data[0]) break;
		L.data[n] = L.data[i];
		n = i;
	}
	L.data[n] = L.data[0];
}

void Heap(List &L){
	for(int i = L.length/2; i>0; i--) Adjust(L,i,L.length);
	for(int i = L.length; i>0; i--){
		L.data[0] = L.data[i];
		L.data[i] = L.data[1];
		L.data[1] = L.data[0];
		Adjust(L,1,i-1);
	}
}

int main(){
	List L;
	Create(L);
	print(L);
	
	Bub(L);
	
	print(L);
	return 0;
}

































