#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	while(1){
		long n;
		scanf(" %ld", &n);
		if(n==0) break;
		
		long s=1;
		for(long i=2; i<=sqrt(n); ++i){
			if(n%i==0){
				if(i==n/i) s+=i;
				else s+=i+n/i;
			}
		}
		
		string ans;
		if(n==1 || s<n) ans="deficient number";
		else if(s==n) ans="perfect number";
		else ans="abundant number";
		
		cout << ans << endl;
	}
}