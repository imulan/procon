#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, m;
		long t[30000];
		t[0]=0;
		
		scanf(" %d %d", &n, &m);
		if(n==0 && m==0) break;
		for(int i=1; i<=n; ++i) scanf(" %ld", &t[i]);
		for(int i=n+1; i<=n+m; ++i) scanf(" %ld", &t[i]);
		sort(t, t+n+m+1);
		
		long max=0;
		for(int i=0; i<n+m; ++i){
			if(max<t[i+1]-t[i]) max=t[i+1]-t[i];	
		}
		
		printf("%ld\n", max);
	}
}