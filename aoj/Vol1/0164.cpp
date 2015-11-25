#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int n, a[25];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf(" %d", &a[i]);
		
		int r=32, now=0;
		while(r>0){
			r -= (r-1)%5;
			printf("%d\n", r);
			r -= a[now%n];
			if(r<0) r=0;
			printf("%d\n", r);
			++now;
		}
	}

	return 0;
}