#include <stdio.h>

int main(void){
	long n, h, a, b, c, d, e;
	long x, y;
	
	scanf(" %ld %ld", &n, &h);
	scanf(" %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);

	long min = n*a;
	
	for(x=0; x<=n; x++){
		y = (long)( (n*e-h-(b+e)*x) / (d+e) ) + 1;
		if(y<0) y=0;
			
		if(a*x+c*y < min) 
			min = a*x + c*y;
	}
	
	printf("%ld\n", min);

	return 0;
}