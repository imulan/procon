#include <cstdio>
#include <iostream>
using namespace std;

const long N=123456;

int main (){
	
	//素数テーブル作成
	bool prime[2*N+1];
	for(long i=0; i<=2*N; ++i) prime[i]=true;
	prime[1]=false;
	prime[2]=true;
	
	for(long i=2; i<=2*N; ++i){
		if(prime[i]){
			for(long j=2; i*j<=2*N; ++j) prime[i*j]=false;	
		}
	}
	
	//処理
	while(1){
		long n, ans=0;
			
		scanf(" %ld", &n);
		if(n==0) break;
		
		for(long i=n+1; i<=2*n; ++i){
			//printf("%ld\n", i);
			if(prime[i]) ans++;
		}
		printf("%ld\n", ans);
	}
	return 0;
}