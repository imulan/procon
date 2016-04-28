#include <iostream>
#include <cstdio>
using namespace std;

#define N 1000000

int main(){
	bool prime[N+1];
	
	for(long i=2; i<=N; ++i) prime[i]=true;

	for(long i=2; i<=N; ++i){
		if(prime[i]){
			for(long j=2; i*j<=N; ++j) prime[i*j]=false;
		}
	}
	
	while(1){
		int n ,count=1;
		long ans=2;
		
		scanf(" %d", &n);
		if(n==0) break;

		for(long i=3; i<=N; i+=2){
			if(count==n) break;
			
			if(prime[i]){
				ans+=i;
				++count;
			}
		}	
	
		printf("%ld\n", ans);	
	}
	return 0;
}