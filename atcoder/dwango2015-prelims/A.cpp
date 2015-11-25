#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, x;
	scanf(" %d %d", &n ,&x);
	long ans=x*540 + (n-x)*525;
	printf("%ld\n", ans);
	return 0;
}