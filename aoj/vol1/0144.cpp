#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, p;
	bool route[101][101];
	
	for(int i=0; i<=100; ++i)
	for(int j=0; j<=100; ++j)
	route[i][j]=false;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		int r, k;
		scanf(" %d %d", &r, &k);
		for(int j=0; j<k; ++j){
			int t;
			scanf(" %d", &t);
			route[r][t]=true;
		}
	}
	
	scanf(" %d", &p);
	for(int i=0; i<p; ++i){
		int cost[101];
		for(int j=0; j<=100; ++j) cost[j]=20000;
		
		int s, d, v;
		scanf(" %d %d %d", &s, &d, &v);
		
		//bfs
		queue<int> que;
		cost[s]=1;
		que.push(s);
		while( !que.empty() ){
			int v=que.front();
			que.pop();
			for(int j=1; j<=n; ++j){
				if(route[v][j] && cost[j] > cost[v]+1){
					cost[j]=cost[v]+1;
					que.push(j);	
				}
			}	
		}
		
		if(cost[d] <= v) printf("%d\n", cost[d]);
		else printf("NA\n");
	}	
	
	
}