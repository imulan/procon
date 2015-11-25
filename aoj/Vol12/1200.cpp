#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	bool prime[33000];
	for(long i=0; i<33000; ++i) prime[i]=true;
	prime[0]=prime[1]=false;
	
	for(long i=2; i<33000; ++i){
		if(prime[i]) for(long j=2; i*j<33000; ++j) prime[i*j]=false;
	}
	
	while(1){
		int n;
		
		scanf(" %d", &n);
		if(n==0) break;
		
		int ans=0;
		for(int i=2; i<=n/2; ++i)
			if(prime[i] && prime[n-i]) ans++;
		
		printf("%d\n", ans);
	}
}