#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, a, b, base, top[100];
	
	scanf(" %d", &n);
	scanf(" %d %d", &a, &b);
	scanf(" %d", &base);
	for(int i=0; i<n; ++i) scanf(" %d", &top[i]);
	
	sort(top, top+n, greater<int>());
	
	double max=(double)base/a;
	
	for(int i=0; i<n; ++i){
		double tmp=base;
		for(int j=0; j<=i; ++j) tmp+=top[j];
		tmp/=(double)a+b*(i+1);
		
		if(tmp>max) max=tmp;
	}
	
	printf("%ld\n", (long)max);
	return 0;
}