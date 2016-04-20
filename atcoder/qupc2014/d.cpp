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

const int INF=1000000001;

typedef pair<int,int> pi;

struct edge{ int to,cost; };
vector<edge> G[30000];

int main()
{
	int n,m,k,s,t;
	int x[101],f[101];

	cin >>n >>m >>k >>s >>t;
	rep(i,m)
	{
		int a,b,d;
		scanf(" %d %d %d",&a,&b,&d);
		G[a].pb(edge{b,d});
		G[b].pb(edge{a,d});
	}
	rep(i,k) scanf(" %d %d",&x[i],&f[i]);
	x[k]=INF;

	priority_queue<pi,vector<pi>,greater<pi>> que;
	//スタート地点からのdijkstra
	int ds[30000];
	fill(ds,ds+n,INF);
	ds[s]=0;
	que.push(pi(0,s));
	while(!que.empty()){
		pi p=que.top();
		que.pop();
		int v=p.se;
		if(ds[v]<p.fi) continue;
		rep(i,(int)G[v].size()){
			edge e=G[v][i];
			if(ds[e.to]>ds[v]+e.cost){
				ds[e.to]=ds[v]+e.cost;
				que.push(pi(ds[e.to],e.to));
			}
		}
	}

	//ゴール地点からのdijkstra
	int dt[30000];
	fill(dt,dt+n,INF);
	dt[t]=0;
	que.push(pi(0,t));
	while(!que.empty()){
		pi p=que.top();
		que.pop();
		int v=p.se;
		if(dt[v]<p.fi) continue;
		rep(i,(int)G[v].size()){
			edge e=G[v][i];
			if(dt[e.to]>dt[v]+e.cost){
				dt[e.to]=dt[v]+e.cost;
				que.push(pi(dt[e.to],e.to));
			}
		}
	}

	//rep(i,n) printf(" %d: %d, %d\n",i,ds[i],dt[i]);

	int ct=upper_bound(x,x+k+1,ds[t])-x-1;
	if(ct==k) ct=k-1;
	int ans=f[ct];
	//printf("ct =%d, ans=%d\n", ct,ans);

	rep(i,n)
	{
		if(i==s || i==t) continue;
		
		int ca=upper_bound(x,x+k+1,ds[i])-x-1;
		int cb=upper_bound(x,x+k+1,dt[i])-x-1;
		if(ca==k) ca=k-1;
		if(cb==k) cb=k-1;
		//printf(" %d: %d+%d\n",i,f[ca],f[cb]);
		ans=min(ans,f[ca]+f[cb]);
	}

	std::cout << ans << std::endl;
	return 0;
}
