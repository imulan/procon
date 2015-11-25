#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	while(1){
		long n, a, b;
		scanf(" %ld %ld %ld", &n, &a, &b);
		if(n==0) break;
		
		if(a>b) swap(a,b);

		long ans=0;
		bool x[1000001];
		
		for(long i=1; i<=n; ++i) x[i]=false;
		x[0]=true;
		
		//作れない数を探す
		for(long i=0; i<=n; ++i){
			if(x[i]){
				if(i+a<=n) x[i+a]=true;	
				if(i+b<=n) x[i+b]=true;
			}
		}	
		
		for(long i=1; i<=n; ++i)
			if(!x[i]) ++ans;
		
		printf("%ld\n", ans);
	}
}