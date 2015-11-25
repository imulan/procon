#include <cstdio>
#include <iostream>
using namespace std;

const long N=51000;

int main(){
	bool pp[N];
	int ct=0;
	long prime[10000];
	
	for(long i=0; i<N; ++i) pp[i]=true;
	pp[0]=pp[1]=false;
	for(long i=2; i<N; ++i){
		if(pp[i]) for(long j=2; i*j<N; ++j) pp[i*j]=false;
	}
	
	for(long i=2; i<N; ++i)
		if(pp[i]) prime[ct++]=i;	
		
	//printf("%d\n", ct);
	
	while(1){
		long m;
		int a, b;
		
		scanf(" %ld %d %d", &m, &a, &b);
		if(m==0) break;
		
		long max=0, ansp, ansq;
		
		for(int i=0; prime[i]*2<=m; ++i){
			long p=prime[i];
			//printf("i=%d\n", i);
			
			for(int j=i; p*prime[j]<=m; ++j){
				long q=prime[j];
				if(a*q>b*p) break;
				else{
					long t=p*q;
					if(t>max){
						max=t;
						ansp=p;
						ansq=q;	
					}
				}
			}
			
		}
		
		printf("%ld %ld\n", ansp, ansq);
	}
}