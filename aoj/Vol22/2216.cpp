#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long a, b;
		long x, y, z;
		
		scanf(" %ld %ld", &a, &b);
		if(a==0) break;
		
		long r=b-a;
		
		x=r/1000;
		r-=x*1000;
		y=r/500;
		r-=y*500;
		z=r/100;
		
		printf("%ld %ld %ld\n", z, y, x);
	}
}