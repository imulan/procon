#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n, k;
	scanf(" %d %d", &n, &k);
	
	double ans=3.0*(n-1)/n/n/n;
	double tt=1.0/n/n/n;
	double t=6.0*(k-1)*(n-k)/n/n/n;
	
	printf("%.20lf\n", ans+t+tt);
}