//愚直解
//TLEする。

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

//隣接リスト
vector<int> G[1000000];

int main(int argc, char const *argv[]) {
  int i,j;

  //input
  int w,h,n;
  scanf(" %d %d %d",&w,&h,&n);
  rep(i,n){
    int m;
    scanf(" %d",&m);

    vector<int> b(m+1);
    rep(j,m+1) scanf(" %d", &b[j]);

    //隣接リストを構成
    rep(j,m){
      //sからdへ直線的に進む
      int s=b[j],d=b[j+1];

      //進行方向決定
      int dx=0,dy=0;
      if(s%w==d%w){//縦方向
        if(s<d) dy=1;
        else dy=-1;
      }
      else{//横方向
        if(s<d) dx=1;
        else dx=-1;
      }

      //dにたどり着くまでsから進行する
      while(s!=d){
        int nxt=s+(w*dy+dx);
        //printf("now i,j= %d,%d : s=%d, nxt=%d\n",i,j,s,nxt);

        G[s].pb(nxt);
        G[nxt].pb(s);
        s=nxt;
      }
    }
  }
  /*
  rep(i,w*h){
    printf("%d: ",i);
    rep(j,G[i].size()) printf(" %d",G[i][j]);
    printf("\n");
  }
  */

  //地点0からの距離
  int dist[1000000];
  rep(i,1000000) dist[i]=INF;
  dist[0]=0;

  //BFS
  queue<int> que;
  que.push(0);
  while(!que.empty()){
    int v=que.front();
    que.pop();
    rep(i,G[v].size()){
      if(dist[G[v][i]] > dist[v]+1){
        dist[G[v][i]]=dist[v]+1;
        que.push(G[v][i]);
      }
    }
  }

  //output
  if(dist[w*h-1]==INF) printf("Odekakedekinai..\n");
  else printf("%d\n",dist[w*h-1]);
  return 0;
}
