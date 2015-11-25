#include <cstdio>
#include <iostream>
using namespace std;

int w, n, p, a[50], b[50];
int dp[10001][51][51]={0}; //dp[幅][使用枚数][今何番目の写真に注目するか]=重要度の最大値

int dfs(int useW, int useNum, int now){
	int ret;
	
	//見終わった
	if(now==n) ret=0;
	//すでに見た
	else if(dp[useW][useNum][now]>=0) ret=dp[useW][useNum][now];
	//幅オーバー，または枚数オーバーするからで写真が入らない
	else if(a[now]+useW>w || useNum+1>p) ret=dfs(useW, useNum, now+1); 
	else ret=max(dfs(useW, useNum, now+1), dfs(useW+a[now], useNum+1, now+1)+b[now]	);

	return dp[useW][useNum][now]=ret;
}


int main(){
		
	scanf(" %d %d %d", &w, &n, &p);
	for(int i=0; i<n; ++i) scanf(" %d %d", &a[i], &b[i]);
	
	//メモ化再起のための初期化
	for(int i=0; i<=w; ++i)
	for(int j=0; j<=p; ++j)
	for(int k=0; k<=n; ++k)
	dp[i][j][k]=-1;
	
	printf("%d\n", dfs(0,0,0) );
	return 0;
}