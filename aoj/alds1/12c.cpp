#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N=10000;
const long INF=1000000000;

int main(){
	int n;
	vector<pair<int,long> > adj[N]; //重み付き有向グラフの隣接リスト表現
	
	//入力
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int u, k;
		scanf(" %d %d", &u, &k);
		
		for(int j=0; j<k; ++j){
			int v;
			long c;
			scanf(" %d %ld", &v, &c);
			adj[u].push_back(make_pair(v,c)); //vと隣接していてそのエッジの重さがc
		} 	
	}
		
	//PriorityQueueを用いたDijkstra法
	priority_queue<pair<long,int> > pq;
	
	int visit[N]={0};
	
	long cost[N];
	for(int i=0; i<N; ++i) cost[i]=INF;
	cost[0]=0; //始点はコスト０で移動可能	
	pq.push(make_pair(0, 0));
	visit[0]=-1; //訪問済み
	
	while(!pq.empty()){
		pair<long,int> p=pq.top(); //pqにある中でcostが最小のものを取り出す
		pq.pop();
		
		long u=p.second;
		visit[u]=-1; //その頂点を訪問済みにする
		
		//最小値と比較して，最短でなければ無視
		if(cost[u] < p.first*(-1)) continue;	
		
		//隣接している辺の中から
		for(int j=0; j<adj[u].size(); ++j){
			long v=adj[u][j].first; //uに隣接する頂点
			if(visit[v]==-1) continue;
			
			if(cost[v] > cost[u]+adj[u][j].second){
				cost[v] = cost[u]+adj[u][j].second;
				pq.push(make_pair(cost[v]*(-1), v));
				visit[v]=1;
			}
		}
		
	}
	
	for(int i=0; i<n; ++i)
		printf("%d %ld\n", i, (cost[i]==INF ? -1 : cost[i]));
}