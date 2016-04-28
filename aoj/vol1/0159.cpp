#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	while(1){
		long n;
		double best=100;
		long ans;
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		for(long i=0; i<n; ++i){
			long num;
			double h, w;
			scanf(" %ld %lf %lf", &num, &h, &w);	
		
			h/=100;
			double bmi=w/h/h;
			bmi-=22;
			if(bmi<0) bmi = -bmi;
		
			if(bmi<best){
				ans=num;
				best=bmi;	
			}
			else if(bmi==best){
				if(num<ans) ans=num;	
			}
		}
	
		printf("%ld\n", ans);
	}
	return 0;
}