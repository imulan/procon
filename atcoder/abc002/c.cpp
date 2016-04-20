#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int x[3], y[3];
	
	for(int i=0; i<3; ++i)
		scanf(" %d %d", &x[i], &y[i]);
	
	for(int i=2; i>=0; --i){
		x[i]-=x[0];
		y[i]-=y[0];
	}
	
	printf("%lf\n", fabs(x[1]*y[2]-x[2]*y[1])/2.0);
	return 0;
}