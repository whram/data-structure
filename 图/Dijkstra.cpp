#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10240;

typedef pair<int,int> pii;

int N, M;
int pDist[MAX];
vector<pair<int, int> > pMap[MAX];
priority_queue<pii, vector<pii>, greater<pii> > Q;	// 优先队列

void Dijkstra(int s);

int main(){
	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		int s, e, v;
		cin >> s >> e >> v;	// 无向图
		pMap[s].push_back(make_pair(e, v));
		pMap[e].push_back(make_pair(s, v));
	}
	Dijkstra(1);
	return 0;
}

void Dijkstra(int s)
{
for(int i = 1; i <= N; i++)	// 初始化
{ pDist[i] = 2147483647; }
pDist[s] = 0; 
Q.push(make_pair(pDist[s], s));	// 将源点加入队列
while(!Q.empty())
{
pii x = Q.top(); Q.pop();	// 取最短的边
if(x.first != pDist[x.second]) { continue; }	// 防止重复计算
for(int i = 0; i < pMap[x.second].size(); i++)
{
int v = pMap[x.second][i].first;	// 待松弛的顶点
int w = pMap[x.second][i].second;	// 从顶点x.second到顶点i的距离
if(pDist[v] > pDist[x.second] + w)
{
pDist[v] = pDist[x.second] + w;	// 松弛
Q.push(make_pair(pDist[v], v));
}
}
}

for(int i = 1; i <= N; i++)
{
cout << pDist[i] << " ";
}
cout << endl;
}

