#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*Linklist;

Linklist createListF(Linklist &H){
	Node *s;
	H = (Linklist)malloc(sizeof(Node));
	H->next=NULL;
	int x;
	scanf("%d",&x);
	while(x!=9999){
		s = (Node*)malloc(sizeof(Node));
		s->next=H->next;
		s->data=x;
		H->next=s;
		scanf("%d",&x);
	}
	return H;
}

Linklist createListR(Linklist &H){
	H = (Linklist)malloc(sizeof(Node));
	Node *r=H;
	Node *s;
	int x;
	scanf("%d",&x);
	while(x!=9999){
		s = (Node*)malloc(sizeof(Node));
		s->next = r;
		s->data = x;
		r->next = s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return H;
}

Node* getElem(Linklist &H,int i){
	int j=1;
	Node *p=H;
	p = p->next;
	if(i<1)
		return NULL;
	while(j!=i){
		p = p->next;
		j++; 
	}
	return p;
}

int main(){
	Linklist H;
	createListR(H);
	Node *p;
	p=H->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p = p->next;
	}
	printf("end\n");
	
	Node *g;
	int x;
	scanf("%d",&x);
	g = getElem(H,x);
	printf("get:%d",g->data);
	return 0;
}
