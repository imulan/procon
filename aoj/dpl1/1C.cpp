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
	
	//dp[i][j]:=品物1~iの中から選び、ナップサックの大きさがjの時に入れられる商品の価値合計の最大値
	int dp[101][10001]={0};
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<=W; ++j){
			if(j-w[i]>=0)
				dp[i+1][j] = max( dp[i+1][j-w[i]]+v[i], dp[i][j] );
			else dp[i+1][j] = dp[i][j];
		}
	}

	printf("%d\n", dp[N][W]);
}