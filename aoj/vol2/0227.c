#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b){
	if(*a<*b) return 1;
	else if(*a<*b) return -1;
	return 0;
}

int main(void){
	while(1){
		int n, m, i;
		int p[1000];
		long ans=0;
	
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		
		for(i=0; i<n; i++) scanf(" %d", &p[i]);
		qsort(p, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);
		
		for(i=0; i<n; i++)
			if((i+1)%m!=0) ans+=p[i];
			
		printf("%ld\n", ans);
	}
	return 0;
}