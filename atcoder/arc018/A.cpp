#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	double h, bmi;
	scanf(" %lf %lf", &h, &bmi);
	h/=100.0;
	printf("%lf\n", bmi*h*h);
}