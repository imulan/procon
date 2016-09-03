#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const long INF=1000000;

int main(){
	int n, time[300][300];
	long m;
	long ans=INF;
	
	//初期化
	for(int i=0; i<300; ++i)
	for(int j=0; j<300; ++j)
	time[i][j]=-1;
	
	//入力
	scanf(" %d %ld", &n, &m);
	for(long i=0; i<m; ++i){
		int a, b, t;
		scanf(" %d %d %d", &a, &b, &t);
		time[a-1][b-1]=time[b-1][a-1]=t;
	}	
	
	//すべての駅を順に根にしてそれぞれに対しbfsで時間を求める
	for(int i=0; i<n; ++i){
		
		long a[300]; //駅iからかかる最短時間
		a[i]=0;
		for(int j=0; j<i; ++j) a[j]=INF; //未訪問
		for(int j=i+1; j<n; ++j) a[j]=INF; //未訪問
		
		//bfs
		queue<int> que;
		que.push(i);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			
			for(int j=0; j<n; ++j){
				if(time[v][j]!=-1 && a[v]+time[v][j] < a[j]){
					que.push(j);
					a[j]=a[v]+time[v][j];	
				}
			}
			
		}
		
		sort(a, a+n, greater<long>());
		if(a[0]<ans) ans=a[0];
		
		//printf("station %d: %ld\n", i+1, a[0]);
	}
	
	printf("%ld\n", ans);
	return 0;
}