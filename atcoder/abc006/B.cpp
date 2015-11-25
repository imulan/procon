#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long n;
	int a[1000001];
	a[1]=0; a[2]=0; a[3]=1;
	for(long i=4; i<=1000000; ++i) a[i] = (a[i-1] + a[i-2] + a[i-3])%10007;
	
	scanf(" %ld", &n);
	printf("%d\n", a[n]);
	
	return 0;
}