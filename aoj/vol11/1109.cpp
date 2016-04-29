#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long z;
	
		scanf(" %ld", &z);
		if(z==0) break;
		
		long cube=z*z*z;
		long ans=cube;
		
		//x,yの組を探す(x>y)
		for(long x=z-1; x>0; --x){
			long c1=x*x*x;
			
			for(long y=x; y>0; --y){
				long c2=y*y*y;	
				long t=cube-c1-c2;
				if(0<t && t<ans) ans=t;
			}
		}
		
		printf("%ld\n", ans);
	}
	return 0;
}