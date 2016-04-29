#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int k;
		long ans=0;
		
		scanf(" %d", &k);
		if(k==0) break;
		for(int i=0; i<k*(k-1)/2; ++i){
			int a;
			scanf(" %d", &a);
			ans += a;
		}
		
		printf("%ld\n", ans/(k-1));
	}	
	return 0;
}