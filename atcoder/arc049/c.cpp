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

typedef pair<int,int> pi;

//forward
vector<int> F[1000];
//backward
vector<int> B[1000];

vector<int> T;
vector<bool> vis;
void dfs(int x)
{

}

int main()
{
	int n,a,b;
	cin >>n;
	cin >>a;
	vector<pi> p(a);
	rep(i,n)
	{
		cin >>p[i].fi >>p[i].se;
		--p[i].fi;
		--p[i].se;
	}
	cin >>b;
	vector<pi> q(b);
	rep(i,n)
	{
		cin >>q[i].fi >>q[i].se;
		--q[i].fi;
		--q[i].se;
	}

	//重複除去
	p.erase(unique(all(p)),p.end());
	q.erase(unique(all(q)),q.end());
	a=p.size();
	b=q.size();

	for(const auto &x :p)
	{
		F[x.fi].pb(x.se);
		B[x.se].pb(x.fi);
	}

	//どれともつながっていないものは塗って構わない

	int ans=0;
	//Bの各条件をとるか否か
	rep(mask,1<<b)
	{
		vector<bool> c(n,true);
		//prohibit
		set<int> ph;

		rep(i,b)
		{
			if(mask>>i&1)
			{
				//採用
				//fiを塗り、seを塗らない方針
				ph.pb(q[i].se);
			}
			else
			{
				//不採用
				//scを塗り、fiを塗らない方針
				ph.pb(q[i].fi);
			}
		}

		for(const auto &x : ph)
		{

		}
	}

	std::cout << ans << std::endl;
	return 0;
}
