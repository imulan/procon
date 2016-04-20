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

typedef pair<int,int> pi;
struct edge{ int to,cost; };

vector<edge> G[1000];

int main(int argc, char const *argv[]) {
  int i;

  int n,m,s,t;
  cin >>n >>m >>s >>t;
  --s;
  --t;
  rep(i,m){
    int x,y,d;
    scanf(" %d %d %d",&x,&y,&d);
    --x;
    --y;
    G[x].pb(edge{y,d});
    G[y].pb(edge{x,d});
  }

  priority_queue<pi,vector<pi>,greater<pi>> que;
  //スタート地点からのdijkstra
  int ds[1000];
  fill(ds,ds+n,INF);
  ds[s]=0;
  que.push(pi(0,s));
  while(!que.empty()){
    pi p=que.top();
    que.pop();
    int v=p.sc;
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
  int dt[1000];
  fill(dt,dt+n,INF);
  dt[t]=0;
  que.push(pi(0,t));
  while(!que.empty()){
    pi p=que.top();
    que.pop();
    int v=p.sc;
    if(dt[v]<p.fi) continue;
    rep(i,(int)G[v].size()){
      edge e=G[v][i];
      if(dt[e.to]>dt[v]+e.cost){
        dt[e.to]=dt[v]+e.cost;
        que.push(pi(dt[e.to],e.to));
      }
    }
  }

  int ans=-2;
  rep(i,n){
    if(i==s || i==t) continue;

    if(ds[i]<INF && ds[i]==dt[i]){
      ans=i;
      break;
    }
  }

  std::cout << ans+1 << std::endl;
  return 0;
}
