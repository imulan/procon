#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
	long num;
	long t;
}team;

team a[1000000];
long n, b[1000000];

int main(){
	while(1){
		
		scanf(" %ld", &n);
		if(n==0) break;
		
		for(int i=0; i<n; ++i){
			a[i].t=0;
			scanf(" %ld", &a[i].num);
			for(int j=0; j<4; ++j){
				int p, q;
				scanf(" %d %d", &p, &q);
				a[i].t+=p*60+q;
			}
			b[i]=a[i].t;
		}
		
		sort(b, b+n);
		long c[3];
		c[0]=b[0]; c[1]=b[1]; c[2]=b[n-2];
		
		for(int i=0; i<3; ++i){
			for(long j=0; j<n; ++j){
				if(c[i]==a[j].t) printf("%ld\n", a[j].num);
			}
		}
		
	}
	return 0;
}
		