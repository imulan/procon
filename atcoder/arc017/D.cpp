#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long n, m;
	long a[100000];
	
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i) scanf(" %ld", &a[i]);
	scanf(" %ld", &m);
	for(long i=0; i<m; ++i){
		long t, l, r;
		scanf(" %ld %ld %ld", &t, &l, &r);
		
		if(t!=0){
			for(long j=l; j<r; ++j) a[j]+=t;	
		}
		else{
			
			
			
			
		}
	}
}