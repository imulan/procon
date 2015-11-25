#include <stdio.h>

int main(void){
	int a, b, i=0;
	
	scanf("%d %d", &a, &b);
	if(a>b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	if(b-a > 4) {
		while(b%10 != a){
			b++; 
		 	i++;
		}
		
		printf("%d\n", i);
	}
	else printf("%d\n", b-a);

	return 0;
}