#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main(){
	while(1){
		int n, m, k;
		int t[2][101][101];
		
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		memset(t, -1, sizeof(t));
		
		for(int i=0; i<n; ++i){
			int a, b, time, cost;
			scanf(" %d %d %d %d", &a, &b, &cost, &time);
			t[0][a][b]=t[0][b][a]=cost;
			t[1][a][b]=t[1][b][a]=time;
		}
		
		scanf(" %d", &k);
		for(int i=0; i<k; ++i){
			int p, q, r;
			scanf(" %d %d %d", &p, &q, &r);
			long a[101]; //各駅までの最小値
			
			for(int j=0; j<=100; ++j) a[j]=50000000;
			
			//bfs
			queue<int> que;
			a[p]=0;
			que.push(p);
			while( !que.empty() ){
				int v=que.front();
				que.pop();
				for(int j=1; j<=m; ++j){
					if(t[r][v][j]>=0 && a[j]>t[r][v][j]+a[v]){
						a[j]=t[r][v][j]+a[v];	
						que.push(j);
					}
				}	
			}
			
			printf("%ld\n",a[q]);
		}
	}
}