#include <stdio.h>

int main(void){
	long n, h, a, b, c, d, e;
	long x, y;
	
	scanf(" %ld %ld", &n, &h);
	scanf(" %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);

	long min = n*a;
	
	for(x=0; x<=n; x++){
		for(y=0; y<=n; y++){
			int flag=0;
			
			if(x+y>n) flag=1;
			if(h+b*x+d*y-(n-x-y)*e <= 0) flag=1;
			
			if(a*x+c*y < min && flag==0) 
				min = a*x + c*y;
				
		}	
	}
	
	printf("%ld\n", min);

	return 0;
}