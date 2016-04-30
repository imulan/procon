#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, m, c[20];
	//input
	scanf(" %d %d", &n, &m);
	for(int i=0; i<m; ++i) scanf(" %d", &c[i]);	
	
	//solve
	
	//dp[i]:=i円を支払うために必要なコインの最小枚数
	int dp[50001] = {0};
	//十分に大きい数で初期化
	for(int i=1; i<=50000; ++i) dp[i] = 100000;
	
	for(int i=0; i<=50000; ++i){
		for(int j=0; j<m; ++j){
			if(i+c[j]<=n){
				dp[i+c[j]] = min(dp[i+c[j]],dp[i]+1);	
			}
		}	
	}
	
	printf("%d\n", dp[n]);
}