#include <cstdio>
#include <iostream>
using namespace std;

const long N=1500000;

int main(){
	bool prime[N];
	
	for(long i=2; i<N; ++i) prime[i]=true;
	
	for(long i=2; i<N; ++i){
		if(prime[i])
			for(long j=2; i*j<N; ++j) prime[i*j]=false;
	}	
	
	while(1){
		long n;
		scanf(" %ld", &n);
		if(n==0) break;
		
		long a, b;
		for(long i=n; i<N; ++i){
			if(prime[i]){
				a=i;	
				break;
			}
		}
		for(long i=n; i>0; --i){
			if(prime[i]){
				b=i;	
				break;
			}
		}
		//printf("%ld-%ld=",a, b);
		printf("%ld\n", a-b);
	}
	return 0;
}