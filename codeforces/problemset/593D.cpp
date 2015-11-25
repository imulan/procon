#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

long parent[30][200001];


int main(){
  long n,m;
  cin >> n >> m;

  vector< pair< pair<long,long>,ll > > edge(n-1);
  map< pair<long,long>, ll> E;
  vector<long> G[n]; //隣接リスト
  REP(i,n-1){
    long u,v;
    ll x;
    scanf(" %ld %ld %I64d", &u, &v, &x);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);

    pair<long,long> tmp1=make_pair(u,v);
    pair<long,long> tmp2=make_pair(v,u);

    edge[i]=make_pair(tmp1,x);
    E[tmp1]=x;
    E[tmp2]=x;
  }

  //BFS
  //頂点0を根に
  vector<long> depth(n);
  parent[0][0]=-1;

  for(long i=0; i<n; ++i) depth[i]=-1;
  depth[0]=0;

  queue<long> que;
  que.push(0);
  while(!que.empty()){
    long v=que.front(); que.pop();
    for(long i=0; i<G[v].size(); ++i){
      if(depth[G[v][i]]==-1){ //未訪問
        parent[0][G[v][i]] = v;
        depth[G[v][i]] = depth[v]+1;
        que.push(G[v][i]);
      }
    }
  }

  for(int k=0; k<20; ++k){
    for(long v=0; v<n; ++v){
      if(parent[k][v]<0) parent[k+1][v]=-1;
      else parent[k+1][v]=parent[k][parent[k][v]];
    }
  }

  //for(long i=0; i<n; ++i) printf("%ld: parent %d, depth %ld\n", i, parent[0][i], depth[i]);

  for(long i=0; i<m; ++i){
    int order;
    scanf(" %d", &order);

    if(order==1){
      long a,b;
      ll y;
      scanf(" %ld %ld %I64d", &a, &b, &y);

      a--;
      b--;
      //aとbのLCA=sを求める
      long s=a,t=b;
      //sとtの高さをそろえる
      if(depth[s] > depth[t]) swap(s,t);
      for(int k=0; k<20; ++k){
        if( (depth[t]-depth[s])>>k & 1 ){
          t = parent[k][t];
        }
      }
      //LCA探索
      if(s!=t){
        for(int k=19; k>=0; --k){
          if(parent[k][s] != parent[k][t]){
            s=parent[k][s];
            t=parent[k][t];
          }
        }

        s=parent[0][s];
      }

      while(a!=s){
        pair<long,long> tt=make_pair(a,parent[0][a]);
        a=parent[0][a];
        y/=E[tt];
      }

      ll store[200000];
      long stin=0;
      while(b!=s){
        pair<long,long> tt=make_pair(b,parent[0][b]);
        b=parent[0][b];
        store[stin++]=E[tt];
      }
      for(long i=stin-1; i>=0; --i) y/=store[i];

      printf("%I64d\n", y);
    }
    else{
      long p;
      ll c;
      scanf(" %ld %I64d", &p, &c);
      edge[p-1].second=c;

      pair<long,long> tt=edge[p-1].first;
      E[tt]=c;
      pair<long, long> rt=make_pair(edge[p-1].first.second, edge[p-1].first.first);
      E[rt]=c;

    }
  }

}
