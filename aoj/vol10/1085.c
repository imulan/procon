#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b){
	if(*a<*b) return 1;
	else if(*a>*b) return -1;
	return 0;
}

int main(void){
	while(1){
		int n, s, i, j;
		int r[20000];
		long ans=0;
		
		scanf(" %d %d", &n, &s);
		if(n==0) break;
	
		for(i=0; i<n; i++)
			scanf(" %d", &r[i]);
	
		qsort(r, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	
		for(i=0; i<n-1; i++) {
			if(r[i] > s) ans += n-i-1;
			else{
				for(j=i+1; j<n; j++) {
					if(r[i]+r[j] > s) ++ans;
					else break;
				}
			}
		}
				
		printf("%ld\n", ans);
	}

	return 0;
}