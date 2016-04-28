#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int n,s;

long dp[11][1025][334];
long rec(int now, int state, int sum)
{
	if(dp[now][state][sum]>=0) return dp[now][state][sum];

	long ret=0;
	if(now==n)
	{
		if(sum==s) ret=1;
	}
	else
	{
		for(int i=0; i<=9; ++i)
		{
			//既に使用されているのでダメ
			if(state>>i&1) continue;

			ret+=rec(now+1,state+(1<<i),sum+(now+1)*i);
		}
	}

	return dp[now][state][sum]=ret;
}

int main()
{
	while(scanf(" %d %d",&n,&s)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		printf("%ld\n",rec(0,0,0));
	}
}
