#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n, ans=0;
		scanf(" %d", &n);
		if(n==0) break;
		
		for(long i=1; i<=n; ++i){
			int t=i;
			while(t%5==0){
				t/=5;
				++ans;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}