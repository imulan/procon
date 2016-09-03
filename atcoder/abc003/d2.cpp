#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const long mod=1000000007;
ll pascal[901][901];

ll cal(int a, int b, int c){
	if(a<0 || b<0) return 0;	
	else  return pascal[a*b][c];
}

int main(){
	int r, c, x, y, d, l;
	
	scanf(" %d %d %d %d %d %d", &r, &c, &x, &y, &d, &l);
	
	//使う領域の種類数
	int area = (r-x+1)*(c-y+1);
	
	//枠の中の組み合わせ
	pascal[0][0]=1;
	for(int i=1; i<=x*y; ++i){
		pascal[i][0] = pascal[i][i]=1;
		for(int j=1; j<i; ++j) pascal[i][j]=(pascal[i-1][j-1] + pascal[i-1][j])%mod;
	}
	
	//包除原理の適用
	ll ans = cal(x, y, d+l);
	ans -= 2*cal(x-1, y, d+l) + 2*cal(x,y-1,d+l);
	ans += cal(x-2, y, d+l) + cal(x, y-2, d+l) + 4*cal(x-1, y-1, d+l);
	ans %=mod;
	ans -= 2*cal(x-1, y-2, d+l) + 2*cal(x-2, y-1, d+l);
	ans += cal(x-2, y-2, d+l);
	ans%=mod;
	ans = (ans+mod)%mod;
	//ここまでで配置箇所の組み合わせ数が求まる
	
	ans *= pascal[d+l][d]; //d+l箇所の配置場所候補のうちd箇所の机の設置方法
	ans %= mod;
	
	printf("%lld\n", ans*area%mod);
	
	return 0;
}