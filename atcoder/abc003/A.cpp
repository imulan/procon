#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	double ans=0;
	scanf(" %d", &n);
	
	for(int i=1; i<=n; ++i)
		ans += i*10000/(double)n;	
	
	printf("%ld\n", (long)ans);
	return 0;
}