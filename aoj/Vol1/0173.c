#include <stdio.h>

typedef struct{
	char name[20];
	int p;
	long m;
}classes;

int main(void){
	classes cla[9];
	int a, b, i;
	
	for(i=0; i<9; i++){
		scanf(" %s %d %d", cla[i].name, &a, &b);
		cla[i].p = a+b;
		cla[i].m = 200*a + 300*b;
	}
		
	for(i=0; i<9; i++)
		printf("%s %d %ld\n", cla[i].name, cla[i].p, cla[i].m);
	
	return 0;
}