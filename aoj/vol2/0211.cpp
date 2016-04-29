#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

long gcd(long x, long y){
	if(x<y)	swap(x,y);
	
	if(y==0) return x;
	else return gcd(y, x%y);
}

long lcm(long x, long y){
	return x*y/gcd(x,y);	
}

int main(){
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		
		pair<long,long> p[10];
		set<pair<long,long> > S;		

		for(int i=0; i<n; ++i){
			scanf(" %ld %ld", &p[i].first, &p[i].second);
			
			int div=gcd(p[i].first, p[i].second);
			p[i].first /= div;
			p[i].second /= div;
			S.insert(p[i]);
		}
		
		long T=p[0].first;
		for(int i=1; i<n; ++i){
			T = lcm(T, p[i].first);	
		}
		//printf("T= %ld\n", T);
		//printf("size= %ld\n", S.size());
		
		if(S.size()==1) for(int i=0; i<n; ++i) printf("1\n");
		else for(int i=0; i<n; ++i) printf("%ld\n", T/p[i].first*p[i].second);
	}
}