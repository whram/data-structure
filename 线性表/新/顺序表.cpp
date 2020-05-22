#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include <io.h>


#define DataSize 20

typedef int ElemType;

int visit(int i, int e){
	printf("��%d��Ԫ��: %d\n", i, e);
	return 0;
}

/* ��̬���� */ 
typedef struct{
	ElemType data[DataSize];
	int length;
}SqList;

/* ��ʼ�� */
bool InitList(SqList &L){
	L.length = 0;
	return true;
}

/* �������� */ 
bool ListInsert(SqList &L, int i, ElemType e){
	if(L.length == DataSize){
		return false;
	}
	if(i<1 || i > L.length + 1){
		return false;
	}
	int j;
	for(j = L.length; j >= i-1; j--){
		L.data[j+1] = L.data[j];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
}

/* ɾ��Ԫ�� */
bool DeleteElem(SqList &L, int i){
	if(L.length == 0){
		return false;
	}
	if(i<1 || i > L.length-1){
		return false;
	}
	int j;
	for(j = i-1; j < L.length-1; j++){
		L.data[j] = L.data[j+1];
	}
	L.length--;
	return true;
} 

/* ����Ԫ�� ����Ԫ���±� */ 
int FindElem(SqList L, ElemType e){
	if(L.length == 0){
		printf("��Ϊ��\n");
		return 0;
	}
	int i;
	for(i=0; i <= L.length-1; i++){
		if(L.data[i] == e){
			return i+1;
		}
	}
}

int main(){
	SqList L;
	InitList(L);
	int i;
	for(i = 0; i<10; i++){
		ListInsert(L, i+1, i);
	}
	
	ListInsert(L,4,99);
	
	DeleteElem(L, 10);
	
	for(i = 0; i < L.length; i++){
		visit(i+1, L.data[i]);
	}
	return 0;
}
