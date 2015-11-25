#include <stdio.h>

int main(void){
	while(1){
		long n, i, sum=0;
		int a;
		
		scanf(" %ld", &n);
		if(n==0) break;
			
		for(i=0; i<n/4; i++){
			scanf(" %d", &a);
			sum += a;
		}
	
		printf("%ld\n", sum);
	}

	return 0;
}