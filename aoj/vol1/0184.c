#include <stdio.h>

int main(void){
	while(1){
		long n, i;
		long a[7] = {0};
		int age;
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		for(i=0; i<n; i++){
			scanf(" %d", &age);
			if(age>60) age=60;
			
			a[age/10]++;
		}
	
		for(i=0; i<7; i++)
			printf("%ld\n", a[i]);

	}

	return 0;
}