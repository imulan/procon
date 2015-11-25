#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long MOD=1000000007;
long c[5000][5000];

int main(){
	long n, k;
	
	scanf(" %ld %ld", &n, &k);
	
	c[0][0]=1;
	for(long i=1; i<=n+k-1; ++i){
		c[i][0]=1;
		
		long r=min(i,k);
		
		for(long j=1; j<=r; ++j){
			c[i][j]=c[i-1][j-1];
			if(j!=i) c[i][j]+=c[i-1][j];
			c[i][j]%=MOD;
		}
	}
	
	printf("%ld\n", c[n+k-1][k]);
}