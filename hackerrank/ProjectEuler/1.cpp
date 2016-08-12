#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long t;
	cin >> t;
	for(long i=0; i<t; ++i){
		long n;
		scanf(" %ld", &n);
		n--;
		
		long a=n/3, b=n/5, c=n/15;
		long ans=0;
		
		ans+=(3+a*3)*a/2;	
		ans+=(5+b*5)*b/2;	
		ans-=(15+c*15)*c/2;	
		
		printf("%ld\n", ans);
	}
}