#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long n, ans=0;
	
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		long a;
		scanf(" %ld", &a);
		ans+=a;
	}
	
	printf("%ld\n", ans/n);
	return 0;
}