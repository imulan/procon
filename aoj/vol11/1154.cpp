#include <cstdio>
#include <iostream>
using namespace std;

const long N=300000;

int main(){
	bool msp[N+1]; //月曜土曜素数
	
	for(long i=0; i<=5; ++i) msp[i]=false;
	for(long i=6; i<=N; ++i){
		if(i%7==1 || i%7==6)	 msp[i]=true;
		else msp[i]=false;
	}
	for(long i=6; i<=N; ++i){
		if(msp[i]){
			for(long j=1; i*(7*j-1)<=N; ++j){
				long a=7*j-1, b=7*j+1;
				msp[i*a]=false;
				if(i*b<=N) msp[i*b]=false;
			}
		}
	}
	
		
	while(1){
		long n;
		scanf(" %ld", &n);
		if(n==1) break;
		
		printf("%ld:", n);
		
		for(long i=1; 7*i-1<=n; ++i){
			long p=7*i-1;
			long q=7*i+1;
			if(q>N) q=1;
			
			if(n%p==0 && msp[p]) printf(" %ld", p);
			if(n%q==0 && msp[q]) printf(" %ld", q);
		}
		printf("\n");
	}
	return 0;
}