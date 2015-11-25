#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const long N=300000;

int main(){
	long n, q;
	long c[N], lowlim[N+1];
	bool ce[N+1];
	
	for(long i=0; i<=N; ++i) ce[i]=false;
	
	
	scanf(" %ld %ld", &n, &q);
	for(long i=0; i<n; ++i){
		scanf(" %ld", &c[i]);
		ce[c[i]]=true;
	}
	sort(c, c+n);

	long now=0;
	for(long i=0; i<=c[n-1]; ++i){
		lowlim[i]=now;
		
		if(ce[i]) now=i;	
	}
	
	
	for(long t=0; t<q; ++t){		
		long a;
		scanf(" %ld", &a);	
		
		long ans=0, p;
		
		for(long i=c[n-1]; i>0; i=lowlim[i-p]){
			p=i%a;
			ans=max(ans,p);
			
			if(i-p<0) break;
		}
		
		printf("%ld\n", ans);
	}
}