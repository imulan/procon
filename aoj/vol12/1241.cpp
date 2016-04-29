#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){	
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		int ans=0;
		
		for(int a=0; a*a<=n; ++a){
			int p=a*a;	
			for(int b=a; p+b*b<=n; ++b){
				int q=b*b;
				for(int c=b; p+q+c*c<=n; ++c){
					int r=c*c;
					int s=n-p-q-r;
					
					double sq=sqrt(s);
					if(sq>=c && sq-(int)sq==0){
						//printf("%d,%d,%d,%f\n", a, b, c, sq);
						ans++;
					}
					
				}
			}
		}	
		
		printf("%d\n", ans);
	}
}