#include <stdio.h>

int main(void){
	int n, a, b;
	int turn = 1;
	scanf(" %d %d %d", &n, &a, &b);

	while(1){
		turn = 1; 
		n -= a;
		if(n<=0) break;
		turn = 2;
		n-=b;
		if(n<=0) break;
	}
	
	if(turn==1) printf("Ant\n");
	else printf("Bug\n");

	return 0;
}