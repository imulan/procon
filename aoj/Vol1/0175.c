#include <stdio.h>

int main(void){
	while(1){
		long n;
		int four[100]={0};
		int i=0, j;
		
		scanf(" %ld", &n);
		if(n==-1) break;
		else if(n==0) {
			printf("%ld\n", n);
			continue;
		}
		
		while(n > 0){
			four[i] = n%4;
			i++;
			n /= 4;
		}
		
		for(j=i-1; j>=0; j--)
			printf("%d", four[j]);
		printf("\n");

	}

	return 0;
}