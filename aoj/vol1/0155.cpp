#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

struct building{ int b,x,y; };
struct edge{ int to; double cost; };
typedef pair<double,int> pi;

const double INF=1e20;

long dist2(building A, building B)
{
	return (long)(A.x-B.x)*(A.x-B.x)+(long)(A.y-B.y)*(A.y-B.y);
}

int main()
{
	int i,j;
	while(1)
	{
		int n;
		cin >>n;
		if(n==0) break;

		vector<building> v(n);
		rep(i,n)
		{
			scanf(" %d %d %d",&v[i].b,&v[i].x,&v[i].y);
			--v[i].b;
		}

		//be connected?
		vector<edge> G[1000];
		rep(i,n)rep(j,i)
		{
			if(dist2(v[i],v[j])<=50*50)
			{
				G[v[i].b].pb(edge{v[j].b,sqrt(dist2(v[i],v[j]))});
				G[v[j].b].pb(edge{v[i].b,sqrt(dist2(v[i],v[j]))});
			}
		}

		int m;
		cin >>m;
		rep(i,m)
		{
			int s,g;
			scanf(" %d %d",&s,&g);
			--s;
			--g;

			double dist[1000];
			fill(dist,dist+1000,INF);
			dist[s]=0;
			int par[1000];
			fill(par,par+1000,-1);

			//dijkstra
			priority_queue<pi,vector<pi>,greater<pi>> que;
			que.push(pi(0,s));
			while(!que.empty())
			{
				pi p=que.top();
				que.pop();
				int v=p.sc;
				if(dist[v]<p.fi) continue;

				rep(j,(int)G[v].size())
				{
					edge e=G[v][j];
					if(dist[e.to]>dist[v]+e.cost)
					{
						//printf("%d -> %d\n",v,G[v][j]);
						dist[e.to]=dist[v]+e.cost;
						par[e.to]=v;
						que.push(pi(dist[e.to],e.to));
					}
				}
			}

			//search parent
			vector<int> ans;
			ans.pb(g+1);
			int now=g;
			while(par[now]!=-1)
			{
				ans.pb(par[now]+1);
				now=par[now];
			}

			reverse(ans.begin(),ans.end());

			//output
			if(ans[0]!=s+1) printf("NA\n");
			else
			{
				rep(j,(int)ans.size())
				{
					if(j) printf(" ");
					printf("%d", ans[j]);
				}
				printf("\n");
			}
		}

	}
}
