#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define Max 9

typedef struct NODE{
	char data;
	NODE *lchild,*rchild;
}NODE;

void pre(NODE *T){
	NODE *S=NULL;
	NODE *Stack[Max];
	int top = 0;
	Stack[++top]=T;
	while(top!=0){
		S = Stack[top--];
		printf("%c\n",S->data);
		if(S->rchild!=NULL) Stack[++top]=S->rchild;
		if(S->lchild!=NULL) Stack[++top]=S->lchild;
	}
} 

void in(NODE *S){
	NODE *Stack[Max];
	int top = 0;
	while(top!=0 || S){
		if(S!= NULL){
			Stack[++top] = S;
			S = S->lchild;
		}
		else{
			S = Stack[top--];
			printf("%c\n",S->data);
			S = S->rchild;
		}
	}
}

void post(NODE *T){
	NODE *Stack[Max],*S=NULL;
	int top=0;
	while(top != 0 || T){
		if(T){
			Stack[++top] = T;
			T = T->lchild;
		}
		else{
			T = Stack[top];
			if(T->rchild && T->rchild!=S){
				T = T->rchild;
				Stack[++top]=T;
				T = T->lchild;
			}
			else{
				T = Stack[top--];
				printf("%c\n",T->data);
				S = T;
				T = NULL;
			}
		}
	}
}

int main(){
	NODE *Tree[Max+1];
	Tree[0]=(NODE*)malloc(sizeof(NODE));
	Tree[0]->data = NULL;
	for(int i=1;i<=Max;i+=1){
		Tree[i]=(NODE*)malloc(sizeof(NODE));
		Tree[i]->data= 'a'+i-1; 
		Tree[i]->lchild = NULL;
		Tree[i]->rchild = NULL;
	}
	
	for(int i=1;i<=Max;i++){
		int j=2*i;
		if(j<=Max){
		Tree[i]->lchild = Tree[j];}
		j++;
		if(j<=Max){
		Tree[i]->rchild = Tree[j];}
	}
	
	NODE *T = Tree[1];
	post(T);
	
	return 0;
}
