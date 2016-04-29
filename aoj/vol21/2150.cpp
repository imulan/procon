#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	bool prime[200000];
	long p[20000]; //素数が小さい順に入っている
	p[0]=2;
	
	for(long i=0; i<200000; ++i) prime[i]=true;
	prime[0]=prime[1]=false;
	for(long i=0; i<200000; ++i){
		if(prime[i])
			for(long j=2; i*j<200000; ++j) prime[i*j]=false;
	}
	
	long c=1; 
	for(long i=3; i<200000; i+=2){
		if(prime[i]) p[c++]=i;
	}
	
	//printf("c=%ld", c);
	
	while(1){
		long n;
		int q;
		long m[15000];
		
		scanf(" %ld %d", &n, &q);
		if(n==-1 && q==-1) break;
		
		int count=0;
		long t=0;
		
		while(p[count] <= n) ++count;
		
		for(long i=count; i<count+100; ++i){
			for(long j=i; j<count+100; ++j){
				m[t++]=p[i]+p[j];
			}
		}
		sort(m, m+t);
		printf("%ld\n", m[q-1]);
	}
	return 0;
}