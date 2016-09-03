#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	long m;
	long road[301][301];
	long cost[301];
	
	memset(road, -1, sizeof(road));
	memset(cost, -1, sizeof(cost));
	
	//input
	scanf(" %d %ld", &n, &m);
	for(long i=0; i<m; ++i){
		int u, v;
		long len;
		scanf(" %d %d %ld", &u, &v, &len);
		road[u][v]=road[v][u]=len;	
	}
	
	//?????
	//bfs
	queue<int> que;
	cost[1]=0;
	que.push(1);
	while( !que.empty() ){
		int v=que.front();
		que.pop();
			
		
		
	}
	
}