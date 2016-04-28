#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int a[3], n;
		for(int i=0; i<3; ++i) scanf(" %d", &a[i]);
		sort(a, a+3);
		if(a[2]==0) break;
		
		scanf(" %d", &n);
		for(int i=0; i<n; ++i){
			int r;
			scanf(" %d", &r);
	
			if(a[0]*a[0]+a[1]*a[1]<4*r*r) printf("OK\n");
			else printf("NA\n");
		}	
	}

	return 0;
}