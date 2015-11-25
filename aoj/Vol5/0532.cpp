#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	for(int i=0; i<3; ++i){
		int a[3], b[3];
		long c[2]={0};
	
		for(int j=0; j<3; ++j){
			scanf(" %d", &a[j]);
			c[0] += a[j]*(int)pow(60, 2-j);
		}	
		for(int j=0; j<3; ++j){
			scanf(" %d", &b[j]);
			c[1] += b[j]*(int)pow(60, 2-j);
		}
		
		long diff=c[1]-c[0];
		long h, m;
		
		h=diff/3600;
		diff-=3600*h;
		m=diff/60;
		diff-=60*m;
		
		printf("%ld %ld %ld\n", h, m, diff);
	}
	return 0;
}