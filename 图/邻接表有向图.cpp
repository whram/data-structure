#include<stdio.h>
#include<stdlib.h>

#define Max 9999
#define Num 20

typedef struct ArcNode{
	int adjV;
	int weight;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{
	char data;
	struct ArcNode *first;
}VNode, AdjList[Num];

typedef struct {
	AdjList Vex;
	int vexnum,arcnum;
}Graph;

void creatGraph(Graph &G){
	printf("输入定点数和边数：");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	for(int i=0; i<G.vexnum; i++){
		G.Vex[i].data='a'+i;
		G.Vex[i].first = NULL;
	}

	ArcNode *Arc;
	int v1,v2;
	for(int i=0;i<G.arcnum;i++){
		Arc = (ArcNode*)malloc(sizeof(ArcNode));
		scanf("%d,%d",&v1,&v2);
		Arc->adjV = G.Vex[v2].data;
		Arc->weight = 1;
		Arc->next=G.Vex[v1].first;
		G.Vex[v1].first = Arc;
		
		Arc->adjV = G.Vex[v1].data;
		Arc->weight = 1;
		Arc->next=G.Vex[v2].first;
		G.Vex[v2].first = Arc;
	} 
}

int main(){
	Graph G;
	creatGraph(G);
}
