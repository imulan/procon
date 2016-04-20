#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const ll INF=100000000000000000LL;

struct inter{
  ll a,b,c;
};

struct edge{
  int to;
  ll cost;
};

vector<edge> G[100000];

int main(int argc, char const *argv[]) {
  int i;

  int n,m,s,d;
  cin >>n >>m >>s >>d;
  --s;
  --d;

  vector<inter> v(n);
  rep(i,n) scanf(" %lld %lld %lld",&v[i].a,&v[i].b,&v[i].c);
  rep(i,m){
    int x,y;
    ll t;
    scanf(" %d %d %lld",&x,&y,&t);
    --x;
    --y;
    G[x].pb(edge{y,t});
    G[y].pb(edge{x,t});
  }

  ll dist[100000];
  fill(dist,dist+n,INF);
  dist[s]=0;
  queue<int> que;
  que.push(s);
  while(!que.empty()){
    int val=que.front();
    que.pop();
    rep(i,(int)G[val].size()){
      ll t=dist[val];
      //ここまでは待たないといけない
      if(t<v[val].c) t=v[val].c;

      if((t-v[val].c)%(v[val].a+v[val].b)>=v[val].a){//赤信号なので待つ
        t+=(v[val].a+v[val].b)-(t-v[val].c)%(v[val].a+v[val].b);
      }

      if(dist[G[val][i].to]>t+G[val][i].cost){
        dist[G[val][i].to]=t+G[val][i].cost;
        que.push(G[val][i].to);
      }
    }
  }

  std::cout << dist[d] << std::endl;
  return 0;
}
