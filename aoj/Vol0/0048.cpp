#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double w;
	while( scanf(" %lf", &w) != EOF ){
		
		if(w<=48) printf("light fly\n");
		else if(w<=51) printf("fly\n");
		else if(w<=54) printf("bantam\n");
		else if(w<=57) printf("feather\n");
		else if(w<=60) printf("light\n");
		else if(w<=64) printf("light welter\n");
		else if(w<=69) printf("welter\n");	
		else if(w<=75) printf("light middle\n");
		else if(w<=81) printf("middle\n");
		else if(w<=91) printf("light heavy\n");
		else printf("heavy\n");
	}

	return 0;
}