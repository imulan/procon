#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define m 256
const double eps=1e-8;

int main(){
	while(1){
		int n, input[m+1];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=1; i<=n; ++i) scanf(" %d", &input[i]);
		
		int as=-1, aa=-1, ac=-1;
		double minh=10000000;
		
		for(int s=0; s<=15; ++s){
			for(int a=0; a<=15; ++a){
				for(int c=0; c<=15; ++c){
					int r[m+1], o[m+1];
					int occur[m+1];
					
					memset(occur, 0, sizeof(occur));
					
					r[0]=s;
					for(int i=1; i<=n; ++i){
						r[i]=(a*r[i-1]+c)%m;
						o[i]=(input[i]+r[i])%m;
						occur[o[i]]++;
						//printf("o[%d]=%d\n", i, o[i]);
					}
						
					double h=0;
					for(int i=0; i<m; ++i){
						if(occur[i]==0) continue;
						else{
							double tmp=(double)occur[i]/n;
							//printf("tmp=%lf", tmp);
							h-= tmp*log(tmp);	
						}
					}
					//printf("s=%d, a=%d, c=%d, h=%lf\n", s, a, c, h);
					
					if(h+eps<minh){
						minh=h;	
						as=s;
						aa=a;
						ac=c;
					}

				}
			}
		}		
		
		printf("%d %d %d\n", as, aa, ac);
	}
}	