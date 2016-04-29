#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	long n;
	int k;
	
	scanf(" %ld", &n);
	scanf(" %d", &k);
	for(int i=0; i<k; ++i){
		long a, b;
		scanf(" %ld %ld", &a, &b);	
		//対称性を利用して折り返し(1/8サイズになる)
		if(a > (n+1)/2) a=n-a+1;
		if(b > (n+1)/2) b=n-b+1;
		if(a<b) swap(a,b);
		
		long ans=b%3;
		if(ans==0) ans=3;
		printf("%ld\n", ans);
	}
	
	return 0;
}