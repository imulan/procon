#include <stdio.h>

int main(void){
	while(1){
		int n, i;
		long a[100], key;
	
		scanf(" %d", &n);
		if(n==0) break;
		
		for(i=0; i<n; i++) scanf(" %ld", &a[i]);
		scanf(" %ld", &key);
	
		int left=0, right=n-1;
		int count = 0;
		
		while(left <= right){
			++count;
		
			int p = (left+right)/2;
			if(a[p] > key) {
				right = p-1;
			}
			else if(a[p] < key) {
				left = p+1;
			}
			else break;
			
			//printf("%d~%d ;%d\n",left,right, p);
		}
	
		printf("%d\n", count);
	
	}

	return 0;
}