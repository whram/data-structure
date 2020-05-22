#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include <io.h>

#define DataSize 20

typedef int ElemType;

int visit(int i, int e){
	printf("第%d个元素: %d\n", i, e);
	return 0;
}

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/* 初始化单链表 */ 
bool InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	if(!L){
		return false;
	}
	L->next = NULL;
	return true;
}

/* 头插法建表 */ 
bool HInsert(LinkList &L){
	LNode *s;
	int x;
	printf("头插法建表\n");
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return true;
}

/* 尾插法建表 */ 
bool TInsert(LinkList &L){
	LNode *s, *t=L;
	int x;
	printf("尾插法建表\n");
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		t->next = s;
		t = s;
		scanf("%d",&x);
	}
	t->next = NULL; 
	return true;
}

/* 在第i个元素后插入新元素 */
bool ListInsert(LinkList &L,int i, ElemType e){
	LNode *s,*p = L;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	int j;
	for(j = i; j>0; j--){
		p = p->next;
	}
	if(!p){
		return false;
	}
	s->next = p->next;
	p->next = s;
	return true;
}

/* 删除第i个节点 */
bool DeleteNode(LinkList &L, int i){
	LNode *p, *s = L;
	while(--i>0){
		s=s->next;
	}
	p = s->next;
	s->next = p->next;
	free(p);
} 

int main(){
	LinkList L;
	InitList(L);
	HInsert(L);
	LNode *s=L->next;
    int i = 1;
    ListInsert(L,1,100);
    DeleteNode(L,3);
	while(s){
		visit(i++,s->data);
		s = s->next;
	}
	return 0;
}
