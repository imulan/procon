#include <stdio.h>

void swap(long *x, long *y){
	long tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void){
	while(1){
		long a, b;
		long count=0;
	
		scanf(" %ld %ld", &a, &b);
		if(a==0 && b==0) break;
		
		if(a<b) swap(&a, &b);
	
		while(b!=0){	
			a = a%b;
			swap(&a, &b);
			count++;
		}
		
		printf("%ld %ld\n", a, count);
	}

	return 0;
}