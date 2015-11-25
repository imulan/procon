#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int arg=90;
	double x=0, y=0; 
	
	while(1){
		int a, b;
		 scanf(" %d,%d", &a, &b);
		if(a==0 && b==0) break;
		x+=a*cos(arg*2*M_PI/360);
		y+=a*sin(arg*2*M_PI/360);
		arg-=b;
	}
	
	printf("%d\n%d\n", (int)x, (int)y); 
	return 0;
}