//修正解

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

int x[1000][1000]={0};
int y[1000][1000]={0};

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

    //辺の通過回数を累積和でとる
    rep(j,m){
      //sからdへ直線的に進む
      int s=b[j],d=b[j+1];
      //s<dにしておく(進行方向を正にするため)
      if(s>d) swap(s,d);
      //進行方向
      if(s%w==d%w){//縦方向
        int f=s%w;
        y[f][s/w]+=1;
        y[f][d/w]-=1;
      }
      else{//横方向
        int f=s/w;
        x[f][s%w]+=1;
        x[f][d%w]-=1;
      }
    }
  }

  //累積和を取る
  rep(i,h)rep(j,w-1) x[i][j+1]+=x[i][j];
  rep(i,w)rep(j,h-1) y[i][j+1]+=y[i][j];

  /*
  printf(" focus on x::\n");
  rep(i,h){
    rep(j,w) printf(" %d",x[i][j]);
    printf("\n");
  }
  printf(" focus on y::\n");
  rep(i,w){
    rep(j,h) printf(" %d",y[i][j]);
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

    //現在位置の確認
    int nx=v%w,ny=v/w;

    //横移動は 右:x[ny][nx]、左x[ny][nx-1]による判定
    if(nx<w-1 && x[ny][nx]>0){//右
      int nxt=v+1;
      if(dist[nxt]>dist[v]+1){
        dist[nxt]=dist[v]+1;
        que.push(nxt);
      }
    }
    if(nx-1>=0 && x[ny][nx-1]>0){//左
      int nxt=v-1;
      if(dist[nxt]>dist[v]+1){
        dist[nxt]=dist[v]+1;
        que.push(nxt);
      }
    }

    //縦移動は 上:y[nx][ny]、下:y[nx][ny-1]による判定
    if(ny<h-1 && y[nx][ny]>0){//上
      int nxt=v+w;
      if(dist[nxt]>dist[v]+1){
        dist[nxt]=dist[v]+1;
        que.push(nxt);
      }
    }
    if(ny-1>=0 && y[nx][ny-1]>0){//下
      int nxt=v-w;
      if(dist[nxt]>dist[v]+1){
        dist[nxt]=dist[v]+1;
        que.push(nxt);
      }
    }

  }

  //output
  if(dist[w*h-1]==INF) printf("Odekakedekinai..\n");
  else printf("%d\n",dist[w*h-1]);
  return 0;
}
