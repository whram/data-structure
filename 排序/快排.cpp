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

int Partition(List &L,int low,int high){
	L.data[0] = L.data[low];
	while(low<high){
		while(low<high && L.data[0]<=L.data[high]) high--;
		L.data[low]=L.data[high];
		while(low<high && L.data[0]>=L.data[low]) low++;
		L.data[high] = L.data[low];
	}
	L.data[low] = L.data[0];
	return low;
}

void Qsort(List &L,int low,int high){
	if(low<high){
		int m=Partition(L, low, high);
		Qsort(L,low,m-1);
		Qsort(L,m+1,high);
	}
}

void QSort2(List &L){
	int st[L.length], top = 0;
	int low = 1, high = L.length;
	st[++top] = low; st[++top] = high; 
	while(top!=0){
		high = st[top--]; low = st[top--];
		int m = Partition(L,low,high);
		if(low<m-1){
			st[++top]=low, st[++top]=m-1;
		}
		if(m+1<high){
			st[++top] = m+1, st[++top] = high;
		}
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
	
	QSort2(L);
	print(L);

	return 0;
}
