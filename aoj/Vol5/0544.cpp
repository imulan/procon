#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n, m, now=0;
		int f[1000], t[1000];
		bool flag=false;
		
		scanf(" %d %d", &n, &m);
		if(n==0 && m==0) break;
	
		for(int i=0; i<n; ++i) scanf(" %d", &f[i]);
		for(int i=0; i<m; ++i) scanf(" %d", &t[i]);
		
		for(int i=0; i<m; ++i){
			now+=t[i];
			//printf("now:%d\n", now);
			
			if(now>=n-1) {
				printf("%d\n", i+1);
				break;
			}
			now+=f[now];
			
			//printf("now:%d\n", now);
			
			if(now>=n-1) {
				printf("%d\n", i+1);
				break;
			}
		}
		
	}

	return 0;
}