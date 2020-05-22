#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 32676
/**
 Dijkstra �㷨����������ͼ��һ��
          ���㵽 ��������ж����
          ��̾�����㷨
*/
/***
     -1 ��ʾ����֮����������޴�
     path[v] ��ʾ��������������Vx�� v �����·��
     ·�� = path[v][0],v,path[v][1],path[v][2] ֱ��һ��path[v][x] == -1
 
     Length[v] ������Vx�� v ����̳��ȣ�Ȩ֮��
 
     ����ע��:
**/
typedef struct graph{
    int **p;
    int vertNum;
    int arcNum;
}*Graph,g;
typedef struct l{
   int* le;
   bool* isIn;
}*Le;
int VETNUM=6;
void init(Le &L,int **&P,Graph &G);
void Dijikstra(Le &L,int **&P,Graph &G,int &V);
int lastInsert(int *&p,int &x);
void myprint(Le &L,int**&p);
int main(){
   Le Length; // ĳ�����㵽�������ж������̾���
   int **Path;  // ·��
   int Vx;     //   ĳ������
   Graph G;    // ͼ
   init(Length,Path,G);
   printf("Enter the begin vertex:\n");
   scanf("%d",&Vx);
   Dijikstra(Length,Path,G,Vx);
   myprint(Length,Path);
}
void myprint(Le &L,int**&p){
    int i,j;
    for(i=0;i<6;i++){
        printf("%d:\t",L->le[i]);
        for(j=0;j<6;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
 
    }
}
int lastInsert(int *&p,int &x){
     int i;
     for(i=0;i<VETNUM;i++){
        if(p[i]==-1){
          p[i] = x;
          return 1;
        }
     }
}
void init(Le &L,int **&P,Graph &G){
     int data[6][6] =  {{-1	,-1	,10	,-1	,30	,100}	,{	-1	,-1	,5	,-1	,-1	,-1	},
                 		{-1	,2	,-1	,50	,-1	,-1	}	,{	-1	,-1	,-1	,-1	,-1	,10	},
                  		{-1	,-1	,-1	,20	,-1	,60	}	,{	-1	,-1	,-1	,-1	,-1	,-1	}};
    
	 int data1[6][6] = {{-1	,1	,20	,80	,-1	,400}	,{	2	,-1	,-1	,-1	,-1	,700},
                        {40	,6	,-1	,4	,-1	,100}	,{	-1	,-1	,-1	,-1	,4	,-1	},
                        {-1	,-1	,-1	,-1	,-1	,3	}	,{	-1	,-1	,-1	,-1	,-1	,-1	}};
     int vextnum = 6;
     int i,j;
     G = (Graph)calloc(sizeof(g),1);
     G->p = (int**)malloc(sizeof(int*)*6);
     P = (int**)malloc(sizeof(int*)*6);
     L = (Le)calloc(sizeof(struct l),1);
     L->le = (int*)calloc(sizeof(int),6);
     L->isIn = (bool*)calloc(sizeof(bool),6);
     for(i=0;i<6;i++){
        G->p[i] = (int*)malloc(sizeof(int)*6);
        P[i] = (int *)calloc(sizeof(int),6);
     }
     G->vertNum = 6;
     for(i=0;i<vextnum;i++)
        for(j=0;j<vextnum;j++)
           G->p[i][j] = data[i][j],P[i][j]= -1;
 
    /***
     for(i=0;i<6;i++)
        printf("%d\n",L->isIn[i]);
     printf("xsaxas");
    */
}
void Dijikstra(Le &L,int **&P,Graph &G,int &V){
   int Vk;
   int i,j;
   int Min;
   int check=0;
   /**
      ���Ƚ�L��ʼ��  �����������һ��
      V �������������Сֵ
   **/
   for(i=0;i<G->vertNum;i++){
       L->le[i] = G->p[V][i];
       //printf("%d\t",L->le[i]);
       if(L->le[i] > -1)
        check =1;
  }
  if(check==0)
    printf("Error!!"),exit(0);
   for(i=1;i<G->vertNum;i++){
        Min = INT_MAX;
      for(j=0;j<G->vertNum;j++)
       if(!L->isIn[j])
       {
           if(L->le[j]!=-1&&L->le[j]<Min)
           {
             Vk = j, Min= L->le[j];
           }
       }
      L->isIn[Vk] = true;          //  ������Vx����ĵ���뵽����һ��������
                                   //  Ҳ����˵��һ�β�Ҫ�Ƚ�
 
      lastInsert(P[V],Vk);
    for(j=0;j<G->vertNum;j++){
 
           if((G->p[Vk][j]!=-1)&&!L->isIn[j]
              &&(Min+G->p[Vk][j]<L->le[j]))
           {
                 L->le[j] = Min+G->p[Vk][j];
                 lastInsert(P[j],Vk);
                 lastInsert(P[j],j);
           }
           if(L->le[j]==-1&&(G->p[Vk][j]!=-1))
           {
                L->le[j] = Min+G->p[Vk][j];
                 lastInsert(P[j],Vk);
                 lastInsert(P[j],j);
           }
 
           }
}
}
