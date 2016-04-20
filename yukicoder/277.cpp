#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int N=100000;
const int INF=12345678;

vector<int> G[N];

int main()
{
	int i;

	int n;
	scanf(" %d",&n);
	rep(i,n-1)
	{
		int x,y;
		scanf(" %d %d",&x,&y);
		--x;
		--y;
		G[x].pb(y);
		G[y].pb(x);
	}

	int r[N],l[N];
	fill(r,r+n,INF);
	fill(l,l+n,INF);

	bool leaf[N];
	fill(leaf,leaf+n,false);

	queue<int> q;

	//まず根からBFS
	q.push(0);
	r[0]=0;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();

		bool isLeaf=true;
		rep(i,G[v].size())
		{
			if(r[G[v][i]]>r[v]+1)
			{
				r[G[v][i]]=r[v]+1;
				q.push(G[v][i]);
				isLeaf=false;
			}
		}

		leaf[v]=isLeaf;
	}

	/*
	rep(i,n) printf(" r[%d] = %d\n",i,r[i]);
	rep(i,n) printf(" leaf[%d] = %d\n",i,leaf[i]);
	*/
	
	//次に葉からBFS
	rep(i,n)
	{
		if(leaf[i])
		{
			q.push(i);
			l[i]=0;
		}
	}
	while(!q.empty())
	{
		int v=q.front();
		q.pop();

		rep(i,G[v].size())
		{
			if(l[G[v][i]]>l[v]+1)
			{
				l[G[v][i]]=l[v]+1;
				q.push(G[v][i]);
			}
		}
	}

	rep(i,n) printf("%d\n", min(r[i],l[i]));
}
