#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int n;
	double p[3100];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		p[i]=0;
		
		int a, b, c, d, e;
		scanf(" %d %d %d %d %d", &a, &b, &c, &d, &e);
		
		p[i]+=a+b+c+d;
		p[i]+=(double)e*110/900;
	}
	
	sort(p, p+n, greater<double>());
	
	printf("%lf\n", p[0]);
}