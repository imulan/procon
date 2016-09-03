#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	long ans=0;
	
	for(int i=0; i<10; ++i){
		long cycle = pow(10,i+1); //i桁目の1サイクル
		
		long r = (n+1)%cycle;
		if(r==0) r=cycle;
		
		ans += (n/cycle)*(cycle/10);
		if(r<=cycle/10){}
		else if(r<=cycle/5) ans+=r-cycle/10;
		else ans+=cycle/10;
		
		//printf("cycle = %ld, r = %ld\nnow :%ld\n",cycle,r, ans);
	}	
	
	printf("%ld\n", ans);
}