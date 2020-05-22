#include <stdio.h>
#include <stdlib.h>

#define InitSize 20

typedef int ElemType;

typedef struct {
	ElemType *data;
	int MaxSize,length;
}Seqlist;

bool createList(Seqlist &L){
	L.data = (ElemType*)malloc(InitSize*sizeof(ElemType));
	if (!L.data){
		return false;
	}
	L.MaxSize = InitSize;
	L.length = 0;
	return true;
}

bool insert(Seqlist &L,int i,ElemType e){
	int j;
	for(j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

int main(){
	Seqlist L;
	createList(L);
	int i;
	for(i=1;i<=10;i++){
		insert(L,i,i);
	}
	for(i=0;i<L.length;i++){
		printf("%d\n",L.data[i]);
	}
	printf("--cut--\n");
	insert(L,5,100);
	for(i=0;i<L.length;i++){
		printf("%d\n",L.data[i]);
	}
	return 0;
}
