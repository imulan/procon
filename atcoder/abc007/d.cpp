#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll func(ll x){
	ll dp[20][2]={0}; //dp[ 上から何桁目 ][ n以下が確定しているか否か ]
	int s[20];

	int size=0;
	ll t=x;
	do{
		t/=10;
		++size;
	}while(t>0);

	for(int i=0; i<size; ++i){
		s[size-1-i]=x%10;
		x/=10;
		//printf("%d: %d\n",size-1-i, s[size-1-i]);
	}

	//初期化
	for(int i=0; i<size; ++i) dp[i][0]=dp[i][1]=0;
	dp[0][0]=1;

	for(int i=0; i<size; ++i){
		for(int j=0; j<10;++j){
			if(j==4 || j==9) continue;

			if(j<s[i]) dp[i+1][1]+=dp[i][0]+dp[i][1];
			else if(j==s[i]){
				dp[i+1][0]+=dp[i][0];
				dp[i+1][1]+=dp[i][1];
			}
			else{
				dp[i+1][1]+=dp[i][1];
			}
		}

		//printf("dp[%d][0]=%lld : dp[%d][1]=%lld\n",i, dp[i][0], i,dp[i][1]);
	}

	return dp[size][0]+dp[size][1];
}

int main(){
	ll a, b;

	cin >>a >>b;
	cout << b-a+1 - (func(b)-func(a-1)) << endl;

	return 0;
}
