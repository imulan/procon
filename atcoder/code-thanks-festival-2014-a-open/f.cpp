#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=100000;

int main()
{
	int i;
	vector<int> G[51];

	int n,m;
	cin >>n >>m;
	rep(i,m)
	{
		//順位:a<b
		int a,b;
		cin >>a >>b;

		//低い方から高い方へ辺をはる
		G[b].pb(a);
	}

	//1を根としてBFS
	bool visit[51];
	fill(visit,visit+n+1,false);
	visit[1]=true;

	queue<int> que;
	que.push(1);
	while(!que.empty())
	{
		int v=que.front();
		que.pop();

		rep(i,G[v].size())
		{
			if(!visit[G[v][i]])
			{
				visit[G[v][i]]=true;
				que.push(G[v][i]);
			}
		}
	}

	int ans=0;
	rep(i,n+1) if(visit[i]) ++ans;
	std::cout << ans << std::endl;
}
