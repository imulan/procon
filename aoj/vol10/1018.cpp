#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	while(scanf(" %d", &n) != EOF){
		long p[100], ans=0;
		for(int i=0; i<n; ++i) scanf(" %ld", &p[i]);
		sort(p,p+n);
		for(int i=0; i<n; ++i) ans+=p[i]*(n-i);
			
		printf("%ld\n", ans);		
	}
	return 0;
}