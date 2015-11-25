#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long N=1000000;

long x[N+1];
long sorted[N+1];

int main(){
	int n, m;
	long a, p;
	long ans=0;
	int seat[1000];
	
	memset(seat, 0, sizeof(seat));
		
	scanf(" %d %d", &n ,&m);
	scanf(" %ld %ld %ld", &x[0], &a, &p);
	
	sorted[0]=x[0];
	for(long i=1; i<n*m; ++i){
		x[i]=(x[i-1]+a)%p;
		sorted[i]=x[i];
	}
	sort(sorted, sorted+n*m);

	//場合分け
	if(a%p==0){
		if(x[0]>x[1]) ans=2*(n-1);
		else ans=0;	
	}
	else{
		for(long i=0; i<m; ++i){
			for(long j=0; j<n; ++j){
				long t=j*m+i;
				//printf("looking :: %ld\n", x[t]);
				
				//2分探索
				long left=0, right=n*m-1;
				long center;
				while(left<right){
					center=(left+right)/2;
					if(sorted[center] < x[t]){
						left = center+1;
					}
					else if(sorted[center] > x[t]){	
						right = center-1;
					}
					else break;	
				}
				
				long dest=center/m; //行くべき列
			
				//printf("  dest=%ld\n", dest);
				
				ans+=fabs( dest - (t/m) ) + fabs( seat[dest] - (t%m) );
				seat[dest]++;
			}
		}
		
	}
	
	printf("%ld\n", ans);
}