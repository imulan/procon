#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int N,W;
	int v[100],w[100];
	
	//input
	scanf(" %d %d", &N, &W);
	for(int i=0; i<N; ++i) scanf(" %d %d", &v[i], &w[i]);
	
	//solve
	
	//dp[i][j]:=品物(i-1)まで入れるかどうか決まっていて、その時の重さがjの時の価値合計の最大値
	int dp[101][10001]={0};
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<=W; ++j){
			if(j-w[i]>=0)
				dp[i+1][j] = max( dp[i][j-w[i]]+v[i], dp[i][j] );
			else dp[i+1][j] = dp[i][j];
		}
	}
	
	int ans=0;
	for(int i=0; i<=W; ++i) ans = max(ans,dp[N][i]);
	printf("%d\n", ans);
}