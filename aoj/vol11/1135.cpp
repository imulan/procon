#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	int m;
	scanf(" %d", &m);
	for(int i=0; i<m; ++i){
		long st;
		int y, n;
		scanf(" %ld %d %d", &st, &y, &n);
		
		long max=0;
		
		for(int j=0; j<n; ++j){
			int k;
			double p;
			long t;
			scanf(" %d %lf %ld", &k, &p, &t);
			
			long tmp=st;
			
			if(k==1){ //単利
				for(int x=0; x<y; ++x){
					long b=floor((double)tmp*p);
					tmp+=b-t;			
				}
			}
			else{ //複利
				long risi=0;
				for(int x=0; x<y; ++x){
					long b=floor((double)tmp*p);
					risi+=b;
					tmp-=t;			
				}
				tmp+=risi;
			}
			
			if(tmp>max) max=tmp;
			//printf(" %ld\n", tmp);
		}
		
		printf("%ld\n", max);	
	}
}