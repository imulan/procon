#include <cstdio>
#include <iostream>
using namespace std;

const long N=1000000;

bool prime[N+1];
bool dp[N+1];

int main(){
	prime[0]=prime[1]=false;
	for(long i=2; i<=N; ++i) prime[i]=true;
	
	for(long i=2; i<=N; ++i){
		if(prime[i]) for(long j=2; i*j<=N; ++j) prime[i*j]=false;
	}
	
	while(1){
		int n;
		long x, c[30];
	
		scanf(" %d %ld", &n, &x);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %ld", &c[i]);
		
		for(long i=0; i<=N; ++i) dp[i]=false;
		
		dp[0]=true;
		for(int i=0; i<n; ++i){
			for(long j=0; j+c[i]<=x; ++j){
				if(dp[j]) dp[j+c[i]]=true;		
			}
		}
		
		long max=0;
		for(long i=0; i<=x; ++i){
			if(dp[i] && prime[i]) max=i;
		}
			
		if(max==0) printf("NA\n");
		else printf("%ld\n", max);
	}
}