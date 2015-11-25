#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, m, p, d[10000];
	long ans=15000000;
	
	scanf(" %ld %ld %ld", &n, &m, &p);
	for(long i=0; i<m; ++i){
		scanf(" %ld", &d[i]);
		d[i] = ( d[i]+n-p )%n;
		//printf(" %ld\n", d[i]);
	}
	p=0; //出発する駅を0に平行移動
	sort(d, d+m);
	
	long cost;
	//時計回り
	cost=d[m-1]*100;
	if(cost<ans) ans=cost;
	//反時計回り
	cost=(n-d[0])*100;
	if(cost<ans) ans=cost;
	//駅d[i]で折り返す
	for(long i=0; i<m-1; ++i){
		cost=0;	
		cost+=2*d[i]*100; //まず駅d[i]まで行って戻る
		cost+=(n-d[i+1])*100; //いってない駅まで反対周りで
		if(cost<ans) ans=cost;
		
		cost=0;
		cost+=2*(n-d[i+1])*100; //まず駅d[i+1]まで行って戻る
		cost+=d[i]*100; //いってない駅まで時計回り
		if(cost<ans) ans=cost;
	}
	
	printf("%ld\n", ans);
	return 0;
}