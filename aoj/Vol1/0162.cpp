#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const long N=1000000;

int main(){
	long ham[550];
	long now=0;
	
	for(int i=0; i<20; ++i){
		for(int j=0; j<13; ++j){
			for(int k=0; k<9; ++k){
				long t=pow(2,i)*pow(3,j)*pow(5,k);
				if(t>N) break;
				ham[now++]=t;			
			}
		}
	}
	
	sort(ham, ham+now);
		
	while(1){
		long a, b, ans=0;
		scanf(" %ld", &a);
		if(a==0) break;
		scanf(" %ld", &b);
		
		for(long i=0; i<N; ++i){
			if(ham[i]>=a){
				now=i;
				break;
			}
		}
		
		for(long i=a; i<=b; ++i){
			if(ham[now]==i){
				++ans;
				++now;
			}
		}
	
		printf("%ld\n", ans);
	}

	return 0;
}