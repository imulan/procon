#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=100000000;

struct edge{ int to,time,cost; };
typedef pair<int,int> pi; //(頂点番号,お金)
typedef pair<int,pi> ppi; //最短距離,(頂点番号,お金)
vector<edge> G[50];

int main()
{
	int i;

	int n,c,v;
	cin >>n >>c >>v;

	vector<int> s(v),t(v),y(v),m(v);
	rep(i,v) scanf(" %d",&s[i]);
	rep(i,v) scanf(" %d",&t[i]);
	rep(i,v) scanf(" %d",&y[i]);
	rep(i,v) scanf(" %d",&m[i]);
	rep(i,v)
	{
		--s[i];
		--t[i];
		G[s[i]].pb(edge{t[i],m[i],y[i]});
	}

	//dijkstra
	int d[50][301];
	fill(d[0],d[50],INF);
	d[0][c]=0;
	priority_queue<ppi,vector<ppi>,greater<ppi>> que;
	que.push(ppi(0,pi(0,c)));
	while(!que.empty()){
		ppi p=que.top();
		que.pop();
		pi val=p.sc;

		if(d[val.fi][val.sc]<p.fi) continue;
		rep(i,G[val.fi].size())
		{
			edge e=G[val.fi][i];
			if(val.sc-e.cost>=0 && d[e.to][val.sc-e.cost]>d[val.fi][val.sc]+e.time)
			{
				d[e.to][val.sc-e.cost]=d[val.fi][val.sc]+e.time;
				que.push(ppi(d[e.to][val.sc-e.cost],pi(e.to,val.sc-e.cost)));
			}
		}
	}

	int ans=INF;
	rep(i,c+1) ans=min(ans,d[n-1][i]);
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
}
