#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		int n;
		scanf(" %d", &n);
		
		long ans=-1;
		
		for(long a=1; a+2<=n; ++a){
			long x=a*a;
			for(long b=a; a+b+1<=n; ++b){
				long y=b*b;
				
				long c=n-a-b;
				if(c<b) break;
				if(x+y>c*c) break;
				
				if(x+y==c*c){
					if(a*b*c>ans) ans=a*b*c;	
				}
			}
		}
		
		printf("%ld\n", ans);
	}
}