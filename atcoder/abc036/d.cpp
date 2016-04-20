#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long mod=1e9+7;

vector<int> G[100000];
int par[100000]={0};

long dp[100000][2];
//現在地、そこの頂点がどっちでも良い/白じゃないとダメ
long rec(int now, int bw)
{
	if(dp[now][bw]>=0) return dp[now][bw];

	long ret=1;

	rep(i,G[now].size())
	{
		int nx=G[now][i];
		if(nx!=par[now])
		{//子
			ret*=rec(nx,!bw);
			ret%=mod;
		}
	}

	//その頂点を黒に塗る場合
	if(bw==0)
	{
		ret+=rec(now,1);
		ret%=mod;
	}

	return dp[now][bw]=ret;
}

int main()
{
	int n;
	cin >>n;
	rep(i,n-1)
	{
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;
		--b;
		G[a].pb(b);
		G[b].pb(a);
	}

	par[0]=0;
	int vis[100000]={0};
	queue<int> que;
	que.push(0);
	vis[0]=1;
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		rep(i,G[v].size())
		{
			if(!vis[G[v][i]])
			{
				que.push(G[v][i]);
				par[G[v][i]]=v;
				vis[G[v][i]]=1;
			}
		}
	}

	memset(dp,-1,sizeof(dp));
	std::cout << rec(0,0) << std::endl;

	return 0;
}
