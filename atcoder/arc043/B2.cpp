#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, d[100000];
const int mod=1e9+7;

int dp[100001][4]={0}; //問題xをy問目に選ぶ組み合わせ
int sum[4]={0}; //今までの累積

int main(){
	//input
	scanf(" %d", &n);
	for(int i=0; i<n; ++i) scanf(" %d", &d[i]);
	
	sort(d, d+n);
	
	int pre=0;
	
	for(int i=0; i<n; ++i){
		dp[i][0]=1; //それぞれの問題を1問目として選ぶ方法は1通り	
		
		while(d[i] >= d[pre]*2){ //この問題を次の問題の候補にできる
			for(int j=1; j<4; ++j){
				sum[j]+=dp[pre][j-1];
				sum[j]%=mod;	
			}
			++pre;
		}
		
		//そこまでの合計が問題iをj問目として選ぶことができる合計の組み合わせになる。
		for(int j=1; j<4; ++j) dp[i][j]=sum[j];
	}
	
	int ans=0;
	for(int i=0; i<n; ++i){
		ans+=dp[i][3];
		ans%=mod;
	}
	printf("%d\n", ans);	
}