#include <stdio.h>
#include <math.h>

int isprime(int x){
	int i, k=1;
	
	for(i=3; i<=sqrt(x); i++){
		if(x%i==0) {
			k=0;
			break;
		}
	}

	return k;
}

int main(void){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		if(n%2 == 0) n--;
		
		while(isprime(n) != 1 || isprime(n-2) != 1){
			n-=2;
		}
		
		printf("%d %d\n", n-2, n);
	}

	return 0;
}