#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	scanf(" %d", &n);
	for(int i=0; i<n;++i){
		long s;
		scanf(" %ld", &s);
		
		printf("Case %d:\n", i+1);
		
		for(int j=0; j<10; ++j){
			s=s*s;
			
			int a[8];
			for(int k=0; k<8; ++k) a[k]=s%(long)pow(10,8-k) / (long)pow(10, 7-k);
			
			s=0;
			for(int k=2; k<6; ++k) s+=a[k]*pow(10,5-k);
			
			printf("%ld\n", s);
		}
	}
	return 0;
}