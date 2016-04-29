#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long d, n, m;
		long a[100000], b[10000];
		
		scanf(" %ld", &d);
		if(d==0) break;
		
		scanf(" %ld %ld", &n, &m);
		a[0]=0;
		for(long i=1; i<n; ++i) scanf(" %ld", &a[i]);
		for(long i=0; i<m; ++i) scanf(" %ld", &b[i]);
		
		sort(a, a+n);
		sort(b, b+m);
		
		//for(long i=0; i<n; ++i) printf(" a[%ld]=%ld\n", i,a[i]);
		
		long ans=0;
		long r=0;
		
		for(long i=0; i<m; ++i){
			if(b[i]==0) continue;
			while(r<n && b[i]>a[r]) r++;	
			
			//printf("b[%ld]=%ld :: r=%ld\n",i,b[i], r);
			
			long tt;
			if(r==n) tt=d;
			else tt=a[r];
			
			long p=b[i]-a[r-1];
			long q=tt-b[i];
			
			//printf("p::%ld, q::%ld\n", p, q);
			
			if(p<q) ans+=p;
			else ans+=q;
			
			//printf("%ld\n", ans);
		}
		
	printf("%ld\n", ans);
	}
}