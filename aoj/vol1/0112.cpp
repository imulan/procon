#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int n, a[10000];
		long ans=0;
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i)
			scanf(" %d", &a[i]);
			
		sort(a, a+n);
		
		for(int i=0; i<n; ++i)
			ans+=a[i]*(n-i-1);

		printf("%ld\n", ans);
	}
	return 0;
}