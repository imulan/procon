#include <cstdio>
#include <iostream>
using namespace std;

const long N=1000000;

int main(){
	bool prime[N+1];
	
	for(long i=0; i<=N; ++i) prime[i]=true;
	for(long i=2; i<=N; ++i){
		if(prime[i]) for(long j=2; i*j<=N; ++j) prime[i*j]=false;
	}
	
	long n;
	scanf(" %ld", &n);
	if(prime[n]) printf("YES\n");
	else printf("NO\n");
}