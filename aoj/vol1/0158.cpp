#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		long n, ans=0;
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		while(n!=1){
			if(n%2==0) n/=2;
			else n=3*n+1;
			++ans;
		}
		
		printf("%ld\n", ans);
	}
	return 0;
}
		