#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, k;
		long s[100];
		scanf(" %d %d", &n, &k);
		if(n==0 && k==0) break;
		for(int i=0; i<k; ++i) scanf(" %ld", &s[i]);
		for(int i=0; i<n; ++i){
			for(int j=0; j<k; ++j){
				int b;
				scanf(" %d", &b);
				s[j]-=b;
			}
		}
		
		bool ans=true;
		for(int i=0; i<k; ++i){
			if(s[i]<0) ans=false;
		}
		
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
}