#include <stdio.h>

int main(void){
	while(1){
		int b, r, g, c, s, t;
		long medal;
	
		scanf(" %d %d %d %d %d %d", &b, &r, &g, &c, &s, &t);
		if(t==0) break;
	
		medal = 100 + (15-2)*(b*5+r*3) + 15*(b+r) + 7*g + 2*c -3*(t-s-b*5-r*3);
	
		printf("%ld\n", medal);
	}

	return 0;
}