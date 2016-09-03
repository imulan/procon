#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, a[20], price=0;
	long x;
	
	scanf(" %d %ld", &n, &x);
	for(int i=0; i<n; ++i){
		scanf(" %d", &a[i]);
	}
	
	for(int i=0; i<n; ++i){
		if(x>=pow(2, n-1-i)){
			x-=pow(2,n-1-i);
			price+=a[n-1-i];
		}
	}

	printf("%d\n", price);
	
	return 0;
}