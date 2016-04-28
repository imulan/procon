#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int w, n, value[1000], weight[1000];
long dp[1001][1001];

long rec(int a, int b){ //お宝aについて，現在の重さb
	if(dp[a][b]>=0) return dp[a][b];
	
	long ret=0;
	
	if(a==n) ret=0;
	else if(b+weight[a]>w){ //重すぎて入れられない
		ret = rec(a+1, b);
	}
	else{
		long p=rec(a+1, b);
		long q=rec(a+1, b+weight[a])+value[a];
		
		if(q>p){
			ret=q;
			//printf("select%d\n", a);
		}
		else ret=p;
	}
	
	return dp[a][b]=ret;
}


int main(){
	int count=1;
	while(1){
		scanf(" %d", &w);
		if(w==0) break;
		scanf(" %d", &n);
		for(int i=0; i<n; ++i) scanf(" %d,%d", &value[i], &weight[i]);
		
		memset(dp, -1, sizeof(dp));
		printf("case %d:\n", count++);
		printf("%ld\n", rec(0, 0));
		
		//蟻本p.56を参照してdpループを正の方向に回すことを考える
		
		
		
		//for(int i=0; i<=w; ++i) printf("dp[%d][%d]=%ld\n", 5, i, dp[5][i]);
		
		
		
		//printf("%ld\n", answ);
	}	
}