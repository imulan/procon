//このコードはTLE


#include <stdio.h>
#include <stdlib.h>

int cmp(const long *a, const long *b){
	if(*a<*b) return 1;
	else if(*a>*b) return -1;
	return 0;
}

int main(void){
	long n, q, x, i, j, max=0;
	long c[300000];
	
	scanf(" %ld %ld", &n, &q);
	for(i=0; i<n; i++) scanf(" %ld", &c[i]);
	
	qsort(c, n, sizeof(long), (int(*)(const void*, const void*))cmp);
	
	//for(i=0; i<n; i++) printf("%ld: %ld\n",i, c[i]);
	
	for(i=0; i<q; i++){
		scanf(" %ld", &x);
		
		for(j=0; j<n; j++){
			if(c[j]%x > max) max = c[j]%x;
			if(max==x-1) break;
		}
		
		printf("%ld\n", max);
	}

	return 0;
}