#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int f(long long a){
	long long p=a;
	int ct=0;
	
	while(p>0){
		ct+=p%10;
		p/=10;
	}	
	
	return ct;
}



int main(){
	long long n;
	
	cin >> n;
	
	long long x=n-163;
	
	int k=0;
	long long ans[200];
	
	for(long long i=x; i<=n; ++i){
		if(i<=0) continue;
		
		if(i+f(i) == n) ans[k++]=i;				
	}
	
	printf("%d\n", k);
	for(int i=0; i<k; ++i) printf("%lld\n", ans[i]);
}