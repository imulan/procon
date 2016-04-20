#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

typedef pair<int,vector<bool>> P;

int n,k;
ll d[50];
vector<int> G[50];

map<P,ll> m;
ll dfs(int now, const vector<bool> &v)
{
	if(m.find(P(now,v))!=m.end()) return m[P(now,v)];

	ll ret=0;
	rep(i,G[now].size())
	{
		if(!v[G[now][i]])
		{
			vector<bool> nv(v);
			nv[G[now][i]]=true;
			ret=max(ret,d[G[now][i]]+dfs(G[now][i],nv));
		}
	}

	return m[P(now,v)]=ret;
}

int main()
{
	cin >>n >>k;
	rep(i,n) cin >>d[i];
	rep(i,k)
	{
		int x,y;
		cin >>x >>y;
		--x;
		--y;
		G[x].pb(y);
		G[y].pb(x);
	}

	ll ans=0;
	rep(i,n)
	{
		vector<bool> visit(n,false);
		visit[i]=true;
		ans=max(ans,d[i]+dfs(i,visit));
	}

	std::cout << ans << std::endl;
	return 0;
}
