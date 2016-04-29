#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int n;
		int k[10000];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %d", &k[i]);
		
		sort(k, k+n, greater<int>());
		if(k[0]<2){
			printf("NA\n");
			continue;
		}
		
		int ans=n;
		for(int i=0; i<n; ++i){
			if(k[i]==0) --ans;
		}
		++ans;
		
		printf("%d\n", ans);
	}
	return 0;
}

