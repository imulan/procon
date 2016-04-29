#include <stdio.h>
#include <math.h>

int main(void){
	int a, b, c;
	while( scanf(" %d %d %d", &a, &b, &c) != EOF){
		double area = sqrt(b*b - (a/2.0)*(a/2.0)) * (a/2.0);
		double y = (b+c)/2.0;
		area += sqrt(y*y - (b/2.0)*(b/2.0)) * (b/2.0) * 2;
	
		printf("%.10lf\n", area);
	}

	return 0;
}