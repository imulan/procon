#include <iostream>
#include <cstdio>
#include <cmath>

int main(){
	while(1){
		int x, h;
		double s=0;
		
		scanf(" %d %d", &x, &h);
		if(x==0) break;
		
		s += x*x;
		
		double r = sqrt(h*h + x*x/4.0);
		s += x*r*2; 
	
		printf("%lf\n", s);	
	}

	return 0;
}