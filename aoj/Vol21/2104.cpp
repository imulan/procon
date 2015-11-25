#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const long N=100000;

int main(){
	int t;
	scanf(" %d", &t);
	for(int times=0; times<t; ++times){
		long n, k, x[N];
		
		scanf(" %ld %ld", &n, &k);
		for(long i=0; i<n; ++i) scanf(" %ld", &x[i]);
		
		long bet[N];
		//bet[i]=distance between x[i] and x[i+1]
		for(long i=0; i<n-1; ++i) bet[i]=x[i+1]-x[i];
		sort(bet, bet+n-1, greater<long>());
		
		long ans=x[n-1]-x[0];
		for(long i=0; i<k-1; ++i) ans-=bet[i];
		
		if(ans<0) ans=0;
		
		printf("%ld\n", ans);
	}
}