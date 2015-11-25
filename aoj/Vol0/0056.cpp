#include <iostream>
#include <cstdio>
using namespace std;

#define N 50000

int main(){
	bool prime[N+1];
	
	for(long i=2; i<=N; ++i) prime[i]=true;

	for(long i=2; i<=N; ++i){
		if(prime[i]){
			for(long j=2; i*j<=N; ++j) prime[i*j]=false;
		}
	}
	
	while(1){
		long n, ans=0;
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		//奇数でも存在する可能性があることを考慮(5=2+3とか)
		for(long i=2; i<=n/2; ++i){		
			if(prime[i] && prime[n-i]) ++ans;	
		}
		
		printf("%ld\n", ans);	
	}
	
	return 0;
}