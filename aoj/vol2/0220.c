#include <stdio.h>
#include <math.h>

int main(void){
	while(1){
		double n;
		int a[12]={0};
		int i;
		
		scanf(" %lf", &n);
		if(n<0) break;
	
		for(i=0; i<12; i++){
			//printf("%lf\n", n);
			if( n>=pow(2.0, 7-i) ){
				n -= pow(2.0, 7-i);
				a[i] = 1;
			}
		
			if(n==0) break;
		}
	
		if(n==0) {
			for(i=0; i<12; i++){
				printf("%d", a[i]);
				if(i==7) printf(".");
			}
			printf("\n");
		}
		else printf("NA\n");
	
	}

	return 0;
}