#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int m, n;
	
	scanf(" %d %d", &m, &n);
	
	int ans=0;
	for(int i=0; i<m; ++i){
		int t=0;
		for(int j=0; j<n; ++j){
			int a;
			scanf(" %d", &a);
			t+=a;
		}
		if(ans<t) ans=t;
	}
	
	printf("%d\n", ans);
}