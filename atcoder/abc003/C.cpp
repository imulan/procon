#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN=100;

int main(){
	int n, k;
	int r[MaxN];
	double rate=0;
	
	scanf(" %d %d", &n, &k);
	for(int i=0; i<n; ++i) scanf(" %d", &r[i]);
	
	sort(r, r+n, greater<int>());
	
	for(int i=0; i<k; ++i)
		rate = (rate+r[k-1-i])/2.0;
	
	printf("%lf\n", rate);
	return 0;
}