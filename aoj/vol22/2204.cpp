#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n, s[100]={0};
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			for(int j=0; j<5; ++j){
				int a;
				scanf(" %d", &a);
				s[i]+=a;
			}
		}
		sort(s, s+n);
		
		printf("%d %d\n", s[n-1], s[0]);
	}
}