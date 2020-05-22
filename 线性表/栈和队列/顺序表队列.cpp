#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front,rear;  //逻辑指针，返回逻辑位置（数组下标） 
}Sqqueue;

void Initqueue(Sqqueue &Q){
	Q.front=0;
	Q.rear=0;
}

bool enter(Sqqueue &Q,ElemType x){
	if(Q.rear==MaxSize){
		return false;
	}
	Q.data[Q.rear++]=x;
	return true;
}

bool out(Sqqueue &Q,ElemType &x){
	if(Q.front==Q.rear){
		return false;
	}
	x=Q.data[Q.front++];
	return true;
}

int main(){
	Sqqueue Q;
	int x,i;
	Initqueue(Q);
	for(i=0;i<6;i++){
		scanf("%d",&x);
		enter(Q,x);
	}
	printf("--cut--\n");
	int L = Q.rear-Q.front;
	for(i=0;i<L;i++){
		out(Q,x);
		printf("%d\n",x);
	}
	return 0;
}
