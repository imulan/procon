#include <iostream>
#include <cstdio>
using namespace std;

const long MAX_N=10000000;
bool isPrime[MAX_N];

int main(){
	for(long i=2; i<=MAX_N; ++i)
		isPrime[i]=true;
		
	for(long i=2; i<=MAX_N; ++i){
		if(isPrime[i]){
			for(long j=2; i*j<=MAX_N; ++j) isPrime[i*j]=false;
		}
	}
	
	while(1){
		long n;
		scanf("%ld", &n);
		if(n==0) break;
	
		if(n%2==0) --n;
	
		for(long i=n; i>=13; i-=2){
			if(isPrime[i]&&isPrime[i-2]&&isPrime[i-6]&&isPrime[i-8]){
				printf("%ld\n", i);
				break;
			}
		}
	}	 

	return 0;
}