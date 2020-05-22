#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 10
typedef struct LNode{
    int data;
    LNode *next;
}LNode ,*LinkList;

void InitList(LinkList &L){
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;
    srand(time(NULL));
    LNode *s;
    for(int i = 0; i<Max; i++){
        s = (LNode*)malloc(sizeof(LNode));
        s->next = L->next;
        s->data = rand()%100;
        L->next = s;
    }
}

void print(LinkList L){
    LNode *p;
    p = L->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}

void dele(LinkList &L){
    LNode *p, *q;
    p = L;
    q = p->next;
    while(q->next!=NULL){
        while(q->next!=NULL && p->next->data<=q->next->data){
        	printf("%d	%d\n",q->next->data,p->next->data);
        	q = q->next;
		}
		if(q->next!=NULL){
			p = q;
			q = q->next;
		}
    }
    p->next = p->next->next;
    //free(p->next);
}

int main(){
    LinkList L;
    InitList(L);
    print(L);
 	printf("--------------\n");
    dele(L);
    printf("--------------\n");
    print(L);
    return 0;
}

