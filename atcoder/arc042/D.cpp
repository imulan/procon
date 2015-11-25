#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	long x, p, a, b;
	scanf(" %ld %ld %ld %ld", &x, &p, &a, &b);
	
	long ans=p;

	if(a<=p-1 && p-1<=b) ans=1;
	else if(b-a>=p) ans=1;
	else if(x==1) ans=1;
	else{
		long t[40]; //xの(2^n)乗
		long ct=0;
		long lim=1;
		
		t[0]=x;
		while(lim*2<a){
			lim*=2;
			ct++;
			t[ct] = (t[ct-1]*t[ct-1])%p;
		}
		
		printf("ct=%ld\n", lim);

		x=t[ct];
		for(long i=lim+1; i<=a; ++i){
			x*=x;
			x%=p;
			printf("%ld\n", x);
		}
		
		for(long i=a; i<=b; ++i){
			ans=min(x,ans);
			x*=x;
			x%=p;
			ans=min(x,ans);
			if(ans==1) break;
		}
		
	}
	
	printf("%ld\n", ans);
}