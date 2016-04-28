#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		int ans=20000;
	
		for(int a=0; a*200<=n; ++a){
			int p=a/5;
			int x=380*5*p*4/5 + 380*(a-5*p);
			int wa=a*200;
			
			for(int b=0; wa+b*300<=n; ++b){
				int q=b/4;
				int y=550*4*q*17/20 + 550*(b-4*q);
				int wb=b*300;
				
				//ここでC店から買うべき数は決まる
				int wc=n-wa-wb;
				if(wc%500!=0) continue;
				else{
					int c=wc/500;
					int r=c/3;
					int z=850*3*r*22/25 + 850*(c-3*r);
					
					if(x+y+z < ans) ans=x+y+z;
				}
				
			}
		}
		
		printf("%d\n", ans);
	}
}