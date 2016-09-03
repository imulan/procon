#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	long c[100];
	double ans=0;
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %ld", &c[i]);	
	
	for(int i=0; i<n; ++i){
		
		int s=0; //c[i]の約数が書かれたコインの枚数
		
		for(int j=0; j<n; ++j){
			if(j==i) continue;		
			
			if(c[i]%c[j] == 0) ++s;
		}
		
		if(s%2==1) ans+=0.5;
		else ans+=(double)(s+2)/(2*s+2);
	}
	
	printf("%lf\n", ans);
	
	return 0;
}