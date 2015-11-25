#include <iostream>
#include <cstdio>

int main(){
	double x, y;
	
	while( scanf(" %lf %lf", &x, &y) != EOF ){
		if(x<35.5 && y<71) printf("AAA\n");
		else if(x<37.5 && y<77) printf("AA\n");
		else if(x<40 && y<83) printf("A\n");
		else if(x<43 && y<89) printf("B\n");
		else if(x<50 && y<105) printf("C\n");
		else if(x<55 && y<116) printf("D\n");
		else if(x<70 && y<148) printf("E\n");
		else printf("NA\n");
	}

	return 0;
}