#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long N=1000000;

long x[N+1];
long sorted[N+1];

long ab(long a){
	return(a>0)?a:-a;
}

int main(){
	int n, m;
	long a, p;
	long ans=0;
	int seat[1000]={0};

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
				//printf("looking :: %ld  ", x[t]);

				long center=lower_bound(sorted, sorted+n*m,x[t])-sorted;

				//printf("center=%ld\n", center);

				long dest=center/m; //行くべき列

				//printf("%ld (%ld,%ld)-> ",x[t], t/m, t%m);
				//printf("go to (%ld, %ld)\n",dest,seat[dest]);

				ans+=ab( dest - (t/m) ) + ab( seat[dest] - (t%m) );
				++seat[dest];
			}
		}

	}

	printf("%ld\n", ans);
}
