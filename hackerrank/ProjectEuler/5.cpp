#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

long gcd(long x, long y){
	if(x<y) swap(x,y);
	
	while(x%y!=0){
		long z=x%y;
		x=y;
		y=z;	
	}
	
	return y;
}

long lcm(long x, long y){
	return x*y/gcd(x,y);
}

int main(){
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		int n;
		scanf(" %d", &n);
		long ans=1;
		for(int i=2; i<=n; ++i) ans=lcm(ans,i);	
		
		printf("%ld\n",ans); 
	}
}