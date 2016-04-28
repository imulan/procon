#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int i=0;
	double m[10000];
	
	while( scanf(" %lf", &m[i]) != EOF ) ++i;
	
	sort(m, m+i);
	printf("%lf\n", m[i-1]-m[0]);

	return 0;
}