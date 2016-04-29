#include <iostream>
#include <cstdio>

int main(){
	while(1){
		int t, n, sum=0;
		
		scanf(" %d", &t);
		if(t==0) break;
		
		scanf(" %d", &n);
		for(int i=0; i<n; ++i){
			int a, b;
			scanf(" %d %d", &a, &b);
			sum += b-a;
		}
	
		if(sum>=t) printf("OK\n");
		else printf("%d\n", t-sum);
	
	}	
	
	return 0;
}