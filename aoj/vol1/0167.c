#include <stdio.h>

int main(void){
	while(1){
		int n, i, j, count=0;
		long a[100];
	
		scanf(" %d", &n);
		if(n==0) break;
		
		for(i=0; i<n; i++)
			scanf(" %ld", &a[i]);
		
		for(i=n; i>0; i--){
			for(j=0; j<i-1; j++){
				if(a[j] > a[j+1]){
					long tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
					++count;
				}
			}
		}
		
		printf("%d\n", count);
	}

	return 0;
}