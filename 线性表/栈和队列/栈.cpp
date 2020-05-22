#include<stdio.h>
#include<stdlib.h>

#define MaxSize 15
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top0,top1; //π≤œÌ’ª 
}Sqstack;

void InitStack(Sqstack &s){
	s.top0=-1;
	s.top1=MaxSize;
}

bool empty0(Sqstack s){
	if(s.top0==-1)
		return true;
	else
		return false;
}

bool empty1(Sqstack s){
	if(s.top1==MaxSize)
		return true;
	else
		return false;
}

bool Push0(Sqstack &S,ElemType x){
	if(S.top0==S.top1-1){
		return false;
	}
	S.data[++S.top0]=x;
	return true;
}

bool Push1(Sqstack &S,ElemType x){
	if(S.top0==S.top1-1){
		return false;
	}
	S.data[--S.top1]=x;
	return true;
}

bool Pop0(Sqstack &S,ElemType &x){
	if(S.top0==-1){
		return false;
	}
	x = S.data[S.top0--];
	return true;
}

bool Pop1(Sqstack &S,ElemType &x){
	if(S.top1==MaxSize){
		return false;
	}
	x = S.data[S.top1++];
	return true;
}

int main(){
	int x;
	Sqstack S;
	InitStack(S);
	printf("s0 it is empty?:%d\n",empty0(S));
	printf("s1 it is empty?:%d\n",empty1(S));
	int i;
	for(i=0;i<2;i++){
		printf("s0 :");
		scanf("%d",&x);
		Push0(S,x);
		printf("s1 :");
		scanf("%d",&x);
		Push1(S,x);
	}
	printf("s0 it is empty?:%d\n",empty0(S));
	printf("s1 it is empty?:%d\n",empty1(S));
	int L=S.top0;
	for(i=0;i<=L;i++){
		Pop0(S,x);
		printf("s0:%d\n",x);
	}
	L=MaxSize-1-S.top1;
	for(i=0;i<=L;i++){
		Pop1(S,x);
		printf("s1:%d\n",x);
	}
	printf("s0 it is empty?:%d\n",empty0(S));
	printf("s1 it is empty?:%d\n",empty1(S));
	return 0;
}
