#include <iostream>
#include <cstdio>
using namespace std;

#define N 6000000

int main(){
	bool isPrime[N];	
	isPrime[0]=false;
	isPrime[1]=false;
	for(long i=2; i<N; ++i) isPrime[i]=true;
	
	for(long i=2; i<=N; ++i){
		if(isPrime[i]){
			for(int j=2; i*j<=N; ++j) isPrime[i*j]=false;	
		}
	}
	
	int n;
	long sum=0;
	
	scanf(" %d", &n);
	for(int i=1; i<=n; ++i) sum+=i;
	
	if(isPrime[sum]) printf("WANWAN\n");
	else printf("BOWWOW\n");
		
	return 0;
}