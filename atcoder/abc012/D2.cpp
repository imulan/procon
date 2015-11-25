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
	
	//すべての駅を順に根にしてそれぞれに対し
	for(int i=0; i<n; ++i){
		//ダイクストラ法
		priority_queue <int>
	
		
	}
	
	printf("%ld\n", ans);
	return 0;
}