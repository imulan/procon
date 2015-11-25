#include <stdio.h>

long fac(int x){
	if(x==0) return 1;
	else return x*fac(x-1);
}

long pp(int a, int b){
	int i;
	long ans=1;
	
	for(i=b; i<=a; i++) ans*=i;
	
	return ans;
}

int main(void){
	while(1){
		long count=0;
		int i, j, k, n;		
		
		scanf(" %d", &n);
		if(n==0) break;
		
		for(i=0; i<=30; i++){
			for(j=0; j<=15; j++){
				for(k=0; k<=10; k++){
					if(i + 2*j + 3*k == n) count += pp(i+j+k, i+1)/fac(j)/fac(k);
					else if(i + 2*j + 3*k > n) break;
				}		
			}
		}
		
		printf("%ld\n", count / 3650 + 1);
	}
	
	return 0;
}