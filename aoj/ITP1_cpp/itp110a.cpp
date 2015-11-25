#include <cstdio>
#include <cmath>

int main(){
	double x1, x2, y1, y2;
	
	scanf(" %lf %lf %lf %lf", &x1, &y1, &x2,&y2);
	printf("%lf\n", sqrt( pow(x2-x1, 2.0) + pow(y2- y1, 2.0) ));
	
	return 0;
}