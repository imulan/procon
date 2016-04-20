#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=1e9+7;
string x,s,t;
long X,S,T;

long dp[1001];
long rec(int now)
{
	if(dp[now]>=0) return dp[now];

	if(now==X) return 1;

	long ret=0;
	if(now+S<=X && x.substr(now,S)==s)
	{
		ret+=rec(now+S);
		ret%=mod;
	}
	if(now+T<=X && x.substr(now,T)==t)
	{
		ret+=rec(now+T);
		ret%=mod;
	}

	return dp[now]=ret;
}

int main()
{
	cin >>x >>s >>t;
	X=x.size();
	S=s.size();
	T=t.size();
	memset(dp,-1,sizeof(dp));
	std::cout << rec(0) << std::endl;
}
