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

const ll INF=2000000000;
const int N=100000;
struct edge{int to,cost;};

//fi:最短距離 sc:頂点番号
typedef pair<int,int> P;
//隣接グラフ
vector<edge> G[N];
//逆向きの辺
vector<edge> R[N];

int main()
{
	int n,m,t;
	cin >>n >>m >>t;
	vector<int> a(n);
	rep(i,n) scanf(" %d", &a[i]);
	rep(i,m)
	{
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		--a;
		--b;
		G[a].pb(edge{b,c});
		R[b].pb(edge{a,c});
	}

	priority_queue<P,vector<P>,greater<P>> que;

	//0->i
	ll d[N];
	fill(d,d+n,INF);
	d[0]=0;
	que.push(P(0,0));
	while(!que.empty()){
	  P p=que.top();
	  que.pop();
	  int v=p.se;

	  if(d[v]<p.first) continue;

	  rep(j,G[v].size()){
		edge e=G[v][j];
		if(d[e.to]>d[v]+e.cost){
		  d[e.to]=d[v]+e.cost;
		  que.push(P(d[e.to],e.to));
		}
	  }
	}

	//i->0
	ll r[N];
	fill(r,r+n,INF);
	r[0]=0;
	que.push(P(0,0));
	while(!que.empty()){
	  P p=que.top();
	  que.pop();
	  int v=p.se;

	  if(r[v]<p.first) continue;

	  rep(j,R[v].size()){
		edge e=R[v][j];
		if(r[e.to]>r[v]+e.cost){
		  r[e.to]=r[v]+e.cost;
		  que.push(P(r[e.to],e.to));
		}
	  }
	}

	///ずっとその場にいる場合
	ll ans=(ll)t*a[0];
	for(int i=1; i<n; ++i)
	{
		ll res=t-d[i]-r[i];
		if(res>0) ans=max(ans,res*a[i]);
	}

	std::cout << ans << std::endl;
	return 0;
}
