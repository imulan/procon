#include <cstdio>
#include <iostream>
using namespace std;

const long N=1000000;

int main(){
	bool prime[N+1];
	
	for(long i=0; i<=N; ++i) prime[i]=true;
	prime[0]=prime[1]=false;
	for(long i=2; i<=N; ++i){
		if(prime[i]) for(long j=2; i*j<=N; ++j) prime[i*j]=false;
	}
	
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		long ans=0;
		for(int i=0; i<n; ++i){
			long p, m;
			scanf(" %ld %ld", &p, &m);	
			
			long x=0;
			int y=0;
			if((p+m)%2==0) y=1;
			
			if(p-m<=2) ++x;
			
			for(long j=p-m+y; j<=p+m-y; j+=2){
				//printf("j=%ld\n", j);
				if(j<2) continue;
				if(j>N) break;
				
				if(prime[j]) x++;
			}
			
			ans+=x-1;
			//printf("%ld\n", ans);
		}	
		
		printf("%ld\n", ans);
	}
}