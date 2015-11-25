#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const long N=200000;

int main(){
	int n, m;
	int ct[21][21];
	
	memset(ct, -1, sizeof(ct));
	
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int a, b, c, d;
		scanf(" %d,%d,%d,%d", &a, &b, &c, &d);	
		ct[a][b]=c;
		ct[b][a]=d;
	}
	
	int x1, x2;
	long y1, y2;
	scanf(" %d,%d,%ld,%ld", &x1, &x2, &y1, &y2);
	y1-=y2;
	
	long cost[21]; //各街までかかる最小の交通費
	for(int i=0; i<=20; ++i) cost[i]=N;
	//行きのbfs
	queue<int> que;
	cost[x1]=0;
	que.push(x1);
	while( !que.empty() ){
		int v=que.front();
		que.pop();	
		for(int i=1; i<=n; ++i){
			if(ct[v][i]>=0 && ct[v][i]+cost[v] < cost[i]){
				cost[i]=ct[v][i]+cost[v];	
				que.push(i);
			}
		}
	}
	y1-=cost[x2];

	for(int i=0; i<=20; ++i) cost[i]=N;
	//帰りのbfs
	cost[x2]=0;
	que.push(x2);
	while( !que.empty() ){
		int v=que.front();
		que.pop();	
		for(int i=1; i<=n; ++i){
			if(ct[v][i]>=0 && ct[v][i]+cost[v] < cost[i]){
				cost[i]=ct[v][i]+cost[v];	
				que.push(i);
			}
		}
	}
	y1-=cost[x1];
	
	printf("%ld\n", y1);
}