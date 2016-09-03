#include <cstdio>
#include <iostream>
using namespace std;

const long INF=1000000000;

int main(){
	int n;
	long m;
	long road[301][301];
	long cost[301];
	
	//initialize
	for(int i=0; i<=300; ++i){
		cost[i]=INF;
		for(int j=0; j<=300; ++j) road[i][j]=INF;				
		road[i][i]=0;
	}
	
	//input
	scanf(" %d %ld", &n, &m);
	for(long i=0; i<m; ++i){
		int u, v;
		long len;
		scanf(" %d %d %ld", &u, &v, &len);
		road[u][v]=road[v][u]=len;	
	}
	
	for(int k=2; k<=n; ++k){
		for(int i=2; i<=n; ++i){
			for(int j=2; j<=n; ++j){
				road[i][j]=min(road[i][j], road[i][k]+road[k][j]);
			}
		}
	}	
	
	long ans=INF;
	for(int x=2; x<=n; ++x){
		for(int y=x+1; y<=n; ++y){
			if(road[1][x]==INF || road[1][y]==INF) continue;		
			ans=min(ans, road[1][x]+road[x][y]+road[y][1]);
		}
	}
	
	if(ans==INF) printf("-1\n");
	else printf("%ld\n", ans);
}