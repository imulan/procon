#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int dp[505][1000];
//(残っている石の数,このターンで取れる石の個数の上限)
int rec(int now, int pre)
{
	if(dp[now][pre]>=0) return dp[now][pre];

	//このターンで勝ち確定
	if(pre>=now) return 1;

	//どこか１つでも(相手のターンで)負けに導ける選択肢があればこのターンで(自分が)勝てる
	int ret=0;
	for(int i=1; i<=pre; ++i)
	{
		if(now-i<0) break;
		ret|=!rec(now-i,i+1);
	}

	return dp[now][pre]=ret;
}

int main()
{
	int n,p;
	cin >>n >>p;
	memset(dp,-1,sizeof(dp));
	printf("%s\n",(rec(n,p)==1)?"first":"second");
}
