#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, k;
	long ans=0;
	
	scanf(" %ld %ld", &n, &k);
	
	long pre=1000000;
	long con=1;
	for(long i=0; i<n; ++i){
		long a;
		scanf(" %ld", &a);
		
		if(pre<a) con++;
		else con=1;
		
		if(con>=k) ++ans;
		
		pre=a;
	}
	
	printf("%ld\n", ans);
}