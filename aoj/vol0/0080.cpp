#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	while(1){
		long q;
		scanf(" %ld", &q);
		if(q==-1) break;
		
		double x=q/2.0;
		while( fabs(x*x*x-q) >= q*pow(10,-5) ){
			x = x-(x*x*x-q)/(3*x*x);
			//printf("now:%lf\n", x);
		}
		
		printf("%lf\n", x);
	}
	
	return 0;
}