#include <stdio.h>

int main(void){
	while(1){
		int n, a, b, c, i;
	
		scanf(" %d", &n);
		if(n==0) break;
	
		for(i=0; i<n; i++){
			int r=0;
			scanf(" %d %d %d", &a, &b, &c);
			
			if(a==100 || b==100 || c==100) r=2;
			else if((a+b)/2.0 >= 90) r=2;
			else if((a+b+c)/3.0 >= 80) r=2;
			else if((a+b+c)/3.0 >= 70) r=1;
			else if( ((a+b+c)/3.0 >= 50) && (a>=80 || b>=80) ) r=1;
			
			if(r==2) printf("A\n");
			else if(r==1) printf("B\n");
			else printf("C\n");
		}
	
	}

	return 0;
}