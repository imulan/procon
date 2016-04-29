#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m;
int c[16],x[20000];

long dp[20001][256];

long rec(int p, int y){ //現在p番目に注目しており、その手前の値はy。x[n]との差の二乗を返す
	if(dp[p][y]>=0) return dp[p][y];
	
	//終条件
	if(p==n) return 0;
	
	long ret=LONG_MAX;
	for(int i=0; i<m; ++i){ //コードブックの値全てに対して再帰をかける
		//次のyの値(丸めが発生することを考慮)
		int ny = y+c[i];
		if(ny<0) ny=0;
		else if(ny>255) ny=255;
		
		//コードブックの選んだ値の中で、二乗和が最小になるよう選ぶ
		ret = min(ret, rec(p+1,ny)+(ny-x[p])*(ny-x[p]));
	}
	
	return dp[p][y]=ret;
}

int main(){
	while(1){		
		//input
		scanf(" %d %d", &n, &m);
		if(n==0) break;
		for(int i=0; i<m; ++i) scanf(" %d", &c[i]);
		for(int i=0; i<n; ++i) scanf(" %d", &x[i]);	
		//solve
		memset(dp,-1,sizeof(dp));
		//最初はy_0=128
		printf("%ld\n", rec(0,128));
	}
}