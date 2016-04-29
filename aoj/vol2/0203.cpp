//DPでできるはずなのにうまくいかない

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x, y, f[15][15];
long dp[15][15]; //座標

long rec(int a, int b){
	if(dp[a][b]>=0) return dp[a][b];

	long ret=0;
	//printf(" %d %d\n", a, b);
	
	if(b>=y-1) ret=1;
	else if(f[b][a]==0){
		for(int i=-1; i<=1; ++i){
			int na=a+i;
			if(na<0 || x<=na) continue;
			
			if(i==0){
				if(f[b+1][na]==1) ret+=0;
				else ret+=rec(na, b+1);
			}
			else{
				if(f[b+1][na]==0) ret+=rec(na, b+1);
				else ret+=0;	
			}
			
		}
	}
	else if(f[b][a]==1) ret=0;	
	else if(f[b][a]==2) ret+=rec(a, b+2);

	//printf(" %d %d ret=%ld\n", a, b, ret);
	return dp[a][b]=ret;	
}

int main(){
	while(1){
		scanf(" %d %d", &x, &y);
		if(x==0) break;	
		for(int i=0; i<y; ++i)
		for(int j=0; j<x; ++j)
		scanf(" %d", &f[i][j]);		
	
		memset(dp, -1, sizeof(dp));
		long ans=0;
		for(int i=0; i<x; ++i){
			if(f[0][i]==0) ans+=rec(i, 0);
			printf(" ans=%ld\n", ans);	
		}
		
		printf("%ld\n", ans);
	}
}