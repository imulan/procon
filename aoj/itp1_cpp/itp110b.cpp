#include <cstdio>
#include <cmath>

int main(){
	double a ,b, c, S, L, h;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	double rad = c/180*M_PI; 
	
	S = a*b*sin(rad)/2.0;
	L = a + b + sqrt(a*a+b*b-2*a*b*cos(rad));
	h = 2*S/a;
	
	printf("%lf\n%lf\n%lf\n", S, L, h);
	
	return 0;
}
	