#include <stdio.h>
#include <math.h>

int main(void){
	long n;
	int flag=0;
	while(scanf(" %ld", &n) != EOF){
		int i, j, a[5];
		char c[5][7];
		
		if(flag==1) printf("\n");		
		
		for(i=0; i<5; i++)
			a[i] = (n/(int)pow(10, 4-i)) % 10;
	
		for(i=0; i<5; i++){
			for(j=0; j<7; j++){
				c[i][j] = '*';
			}
		}
		
		for(i=0; i<5; i++){
			c[i][(a[i]/5>0)?0:1] = ' ';
			c[i][2+a[i]%5] = ' ';
		}
		
		for(i=0; i<7; i++){
			if(i==2) printf("=====\n");
		
			for(j=0; j<5; j++){
				printf("%c", c[j][i]);
			}
			printf("\n");
		}
		
		flag=1;
	}

	return 0;
}