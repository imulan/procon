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

vector<int> G[100000];

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

	vector<int> ans;

	vector<bool> vis(n,false);
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	vis[0]=true;

	while(!pq.empty())
	{
		int v=pq.top();
		pq.pop();
		ans.pb(v+1);
		rep(i,G[v].size())
		{
			if(!vis[G[v][i]])
			{
				vis[G[v][i]]=true;
				pq.push(G[v][i]);
			}
		}
	}

	rep(i,ans.size())
	{
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}
