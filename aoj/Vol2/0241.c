#include <stdio.h>

int main(void){
	while(1){
		int n, i, j;
		int a[4], b[4];
		long c[4];
		
		scanf(" %d", &n);
		if(n==0) break;

		for(i=0; i<n; i++){
			for(j=0; j<4; j++)
				scanf(" %d", &a[j]);
			for(j=0; j<4; j++)
				scanf(" %d", &b[j]);
			
			c[0] = a[0]*b[0] - a[1]*b[1] - a[2]*b[2] - a[3]*b[3];
			c[1] = a[0]*b[1] + a[1]*b[0] + a[2]*b[3] - a[3]*b[2];
			c[2] = a[0]*b[2] - a[1]*b[3] + a[2]*b[0] + a[3]*b[1];
			c[3] = a[0]*b[3] + a[1]*b[2] - a[2]*b[1] +a[3]*b[0];
				
			for(j=0; j<4; j++) {
				printf("%ld", c[j]);
				if(j<3) printf(" ");	
			}
			printf("\n");
		
		}

	}

	return 0;
}