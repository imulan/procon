#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, ans=0;
	long s, t, w;
	
	scanf(" %d %ld %ld %ld", &n, &s, &t, &w);
	
	if(s<=w && w<=t) ans++;
	
	for(int i=0; i<n-1; ++i){
		long a;
		scanf(" %ld", &a);	
		w+=a;
		if(s<=w && w<=t) ans++;	
	}
	
	printf("%d\n", ans);
}