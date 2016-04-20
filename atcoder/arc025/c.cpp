#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=1000000000;

struct edge{int to,cost;};
//fi:最短距離 sc:頂点番号
typedef pair<int,int> P;

//隣接グラフ
std::vector<edge> G[2500];

int main(int argc, char const *argv[]) {
  int i,j;

  //input
  int n,m,r,t;
  scanf(" %d %d %d %d",&n,&m,&r,&t);
  rep(i,m){
    int x,y,z;
    scanf(" %d %d %d",&x,&y,&z);
    --x;
    --y;
    G[x].pb(edge{y,z});
    G[y].pb(edge{x,z});
  }

  long ans=0;

  //目的地Aを固定
  rep(i,n){
    //iからの距離
    int d[2500];
    fill(d,d+n,INF);
    d[i]=0;

    //dijkstra
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,i));
    while(!que.empty()){
      P p=que.top();
      que.pop();
      int v=p.sc;

      if(d[v]<p.first) continue;

      rep(j,G[v].size()){
        edge e=G[v][j];
        if(d[e.to]>d[v]+e.cost){
          d[e.to]=d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }

    //カメの方が先につくためには、d[c]/t<d[b]/r
    //つまりd[c]*r<d[b]*t

    //r倍
    int dr[2500];
    rep(j,n) dr[j]=d[j]*r;
    sort(dr,dr+n);

    //rep(j,n) printf("dr[%d]=%d\n",j,dr[j]);

    //ウサギのスタート地点Bを固定した時、
    rep(j,n){
      if(i==j) continue;
      /*
      printf(" now i:%d,j:%d\n",i,j);
      printf("d[%d]*%d=%d\n",j,t,d[j]*t);
      */
      int ct = upper_bound(dr,dr+n,d[j]*t-1)-dr;

      //printf("ct=%d\n", ct);

      if(r<t) --ct;
      ans+=ct-1;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
