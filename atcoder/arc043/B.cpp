#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int n, d[100000];
const int mod=1000000007;

int dp[100001][4];

int rec(int x, int y){ //問題xをy問目に選ぶ
	if(dp[x][y]>=0) return dp[x][y];
	
	int ret=0;

	if(y==3){ //最後に到達した
		ret=1;
	}
	else{
		int times =4/pow(2,y);
		
		for(int i=x+1; i<=n-3+y; ++i){
			if(d[i]*times > d[n-1]) break;
			
			if(d[x]*2<=d[i]){ //次の問題の候補になり得る
				ret += rec(i, y+1);
				ret%=mod;
			}
		}
	}
	
	//printf("(x,y)=(%d,%d), ret=%d\n", x, y, ret);
	return dp[x][y]=ret;
}


int main(){
	memset(dp, -1, sizeof(dp));
	
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %d", &d[i]);
	
	sort(d, d+n);
	
	int ans=0;
	for(int i=0; i<=n-4; ++i){
		if(d[i]*8<=d[n-1]){
			ans+=rec(i,0);
			ans%=mod;
		}
	}
	
	printf("%d\n", ans);	
}