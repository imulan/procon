#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long n, m;
	
	scanf(" %ld %ld", &n, &m);
	
	long x=-1, y=-1, z=-1;
	
	for(long a=0; (a<=n)&&(2*a<=m)&&(m<=2*a+4*(n-a)); ++a){
		for(long b=n-a; (b>=0)&&(2*a+3*b+4*(n-a-b)<=m); --b){
			long c=n-a-b;
			long leg=2*a+3*b+4*c;
			//printf("(a,b,c)=(%ld,%ld,%ld) : leg=%ld\n", a, b, c,leg);
			
			if(leg==m){
				x=a;	
				y=b;
				z=c;
				break;
			}
			
		}
		if(x!=-1) break;
	} 
	
	printf("%ld %ld %ld\n", x, y, z);
	
	return 0;
}