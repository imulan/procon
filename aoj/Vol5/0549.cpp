#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, m;
	long dist[100001]; //宿1からの距離
	dist[1]=0;
	
	scanf(" %ld %ld", &n, &m);
	for(long i=0; i<n-1; ++i){
		long s;
		scanf(" %ld", &s);	
		dist[i+2]=s+dist[i+1];
	}
	long ans=0;
	long now=1;
	for(long i=0; i<m; ++i){
		long p;
		scanf(" %ld", &p);
		
		if(p>0) ans += dist[now+p]-dist[now];
		else ans += dist[now]-dist[now+p];
		ans %= 100000;
		now+=p;
	}
	
	printf("%ld\n", ans);
}