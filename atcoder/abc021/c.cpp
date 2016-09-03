#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const long MOD=1000000007;

int main(){
	int n, a, b, m;
	int d[101][101]={0}; //道の情報
	int x[200], y[200];
	
	scanf(" %d %d %d %d", &n, &a, &b, &m);
	for(int i=0; i<m; ++i){
		scanf(" %d %d", &x[i], &y[i]);	
		d[x[i]][y[i]]=d[y[i]][x[i]]=1;
	}
	
	//bfs
	queue<int> que;
	int cost[101];
	for(int i=0; i<=100; ++i) cost[i]=300; //十分大きい
	cost[a]=0;
	que.push(a);
	
	while( !que.empty() ){
		int v=que.front();
		que.pop();
		for(int i=1; i<=n; ++i){
			if(d[v][i]==1 && cost[i]>cost[v]+1){
				que.push(i);	
				cost[i]=cost[v]+1;
			}	
		}
		
	}	

	//for(int i=1; i<=n; ++i) printf("%d::%d\n",i, cost[i]);
	
	//逆にたどっていく
	long ans[101]={0};
	ans[b]=1;
	
	//コストがct+1とctの町を結ぶ道を探す
	int ct=cost[b]-1;
	while(ct>=0){
		for(int i=0; i<m; ++i){
			int cx=cost[x[i]], cy=cost[y[i]];
			if(cx==ct+1&&cy==ct){ //xtoy
				ans[y[i]]+=ans[x[i]];
				ans[y[i]]%=MOD;
			}
			else if(cx==ct&&cy==ct+1){
				ans[x[i]]+=ans[y[i]];
				ans[x[i]]%=MOD;
			}
		}	
		
		ct--;
	}

	printf("%ld\n", ans[a]);
}