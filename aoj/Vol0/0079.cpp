#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct{
	double x, y;
}point;

double dist(point a, point b){
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main(){
	point p[20];
	int n=0;
	double s;

	while( scanf(" %lf,%lf", &p[n].x, &p[n].y) != EOF) ++n;

	for(int i=1; i<=n-2; ++i){
		double a=dist(p[0], p[i]), b=dist(p[0], p[i+1]), c=dist(p[i], p[i+1]); 
		double z=(a+b+c)/2.0;
		s+=sqrt(z*(z-a)*(z-b)*(z-c));
	}

	printf("%lf\n", s);

	return 0;
}