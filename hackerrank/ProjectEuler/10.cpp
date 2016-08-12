#include <cstdio>
#include <iostream>
using namespace std;

const long N=1000000;
bool prime[N+1];	

int main(){
	for(int i=0; i<=N; ++i) prime[i]=true;
	prime[0]=prime[1]=false;
	for(long i=2; i<=N; ++i){
		if(prime[i])
			for(long j=2; i*j<=N; ++j) prime[i*j]=false;
	}
	
	long p[100000];
	long now=0;
	for(long i=2; i<=N; ++i){
		if(prime[i]) p[now++]=i;	
	}
	
	//printf("now=%ld\n", now);
	
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		long n;
		scanf(" %ld", &n);
	
		long ans=0;
		for(long j=0; p[j]<=n; ++j) ans+=p[j];
			
		printf("%ld\n", ans);
	}
}