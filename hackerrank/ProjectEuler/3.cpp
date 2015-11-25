//TLE

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

unsigned long long solve(long long x){
	unsigned long long ret=1;
	
	while(x%2==0){
		x/=2;
		ret=2;
	}
	
	unsigned long long p=3;
	while(x!=1){
		while(x%p==0){
			x/=p;
			ret=p;
					printf("p=");
		cout<<p<<endl;

		}
		p+=2;
	}		
	
	return ret;
}


int main(){
	
	int t;
	scanf(" %d", &t);
	for(int i=0; i<t; ++i){
		unsigned long long n;
		cin >> n;
		
		cout << solve(n) << endl;		
	}
}