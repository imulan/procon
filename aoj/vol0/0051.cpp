#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n; ++i){
		long a;
		int p[8], q[8];
		scanf(" %ld", &a);
	
		for(int i=0; i<8; ++i){
			p[i] = ( a%(long)pow(10,8-i) ) / pow(10,7-i);
			q[i]=p[i];
			//printf("%d:%d\n", i, p[i]);
		}	
		
		sort(p, p+8);
		sort(q, q+8, greater<int>());
		
		long x=0, y=0;
		for(int i=0; i<8; ++i){
			x+=p[i]*pow(10,7-i);
			y+=q[i]*pow(10,7-i);
		}
	
		printf("%ld\n", y-x);
	}


	return 0;
}