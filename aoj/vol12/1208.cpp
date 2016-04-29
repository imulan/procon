#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int p, n;
		
		scanf(" %d %d", &p, &n);
		if(p==0) break;	

		int x, y, u, v;
		double rp=sqrt(p);
		double big=10000, small=0;
		
		int re=(int)rp;
			
		for(int i=1; i<=n; ++i){
			for(int j=rp*i; j<=n; ++j){
				double a=(double)j/i;
				
				if(rp<a){
					if(a<big){
						big=a;	
						x=j;
						y=i;
					}
					
					break;
				}
				else{
					if(small<a){
						small=a;
						u=j;	
						v=i;
					}	
				}
		
			}
		}
					
		printf("%d/%d %d/%d\n", x, y, u, v);
	}
}