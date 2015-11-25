#include <stdio.h>
#include <math.h>

int prime(long x){
	int key=1;
	long i;
	
	for(i=3; i<=sqrt(x); i+=2){
		if(x%i==0){
			key=0;
			break;
		}
	}

	return key;
}

int main(void){
	long n;
	while(scanf(" %ld", &n) != EOF){
		long a=n, b=n;
		if(n%2==0) {
			--a;
			++b;
		}else{
			a-=2;
			b+=2;
		}
		 
		if(n==3) {
			a=2;
			b=5;
		}
		else{
			while(prime(a) != 1) a-=2;
			while(prime(b) != 1) b+=2;
		}
		
		printf("%ld %ld\n", a, b);
	}
	
	return 0;
}