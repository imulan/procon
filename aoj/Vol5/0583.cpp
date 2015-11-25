#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	long a[3];
	
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %ld",  &a[i]);
	sort(a, a+n);
	
	for(long i=1; i<=a[0]; ++i){
		bool flag=true;
		
		for(int j=0; j<n;++j){
			if(a[j] % i != 0) {
				flag=false;
				break;
			}
		}	
		
		if(flag) printf("%ld\n", i);
	}
	
	return 0;
}