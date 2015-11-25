#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int t[17][17], dp[66000];

int rec(int a){ //クリア状況a
	if(dp[a]>0) return dp[a];

	if(a==(1<<n)-1) return 0;
	
	int x, y=100000000;
	for(int i=1; i<=n; ++i){ //次に攻略するステージを選ぶ
		if(a>>(i-1) & 1) continue; //既に攻略済み
		else{
			int min=t[i][0];
			int p=0;
			
			//今持っているアイテムを使う時に最小時間を求める
			for(int j=1; j<=n; ++j){
				if(a>>(j-1) & 1){ //既に攻略済み	
					if(min>t[i][j]){
						min=t[i][j];
						p=j;
					}
				}	
			}	
			
			x=rec(a + (1<<(i-1)))+min;
			if(y>x) y=x;
			//printf(" a= %ld, i= %d, x= %d\n", a, i, x);
		}
		
	}
	return dp[a]=y;
}

int main(){
	while(1){
		scanf(" %d", &n);
		if(n==0) break;
		
		for(int i=1; i<=n; ++i)
		for(int j=0; j<=n; ++j)
		scanf(" %d", &t[i][j]);		

		memset(dp, -1, sizeof(dp));
		dp[0]=0;
		printf("%d\n", rec(0));
	}
}