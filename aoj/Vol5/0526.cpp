#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const long N=1200000000;

int main(){
	while(1){
		int n, k;
		scanf(" %d %d", &n, &k);
		if(n==0) break;
		
		long island[101][101];
		memset(island, -1, sizeof(island));
		
		for(int i=0; i<k; ++i){
			int order;
			scanf(" %d", &order);
			if(order==0){ //客の注文
				long cost[101]; //各島までの値段の最小値	
				for(int j=0; j<=100; ++j) cost[j]=N;
				
				int a, b;
				scanf(" %d %d", &a, &b);
				
				//bfs
				queue<int> que;
				cost[a]=0;
				que.push(a);
				while( !que.empty() ){
					int v=que.front();
					que.pop();
					for(int j=1; j<=n; ++j){
						if(island[v][j]>=0 && cost[j]>island[v][j]+cost[v]){
							cost[j]=island[v][j]+cost[v];
							que.push(j);
						}
					}
				}
				
				if(cost[b]==N) printf("-1\n");
				else printf("%ld\n", cost[b]); 
			}
			else if(order==1){ //運行情報の追加
				int c, d;
				long e;
				scanf(" %d %d %ld", &c, &d, &e);
				
				if(island[c][d]==-1 || island[c][d]>e)
					island[c][d]=island[d][c]=e;
			}
		}
	}
}