#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef struct{
  int x,y;
}point;

int main(int argc, char const *argv[]) {
  int i,j;
  int dx[4]={1,0,-1,0};
  int dy[4]={0,-1,0,1};

  //input
  int w,h;
  cin >>w >>h;
  vector<string> f(h);
  rep(i,h) cin >>f[i];

  //最初に見つかった点
  point a;
  bool found=false;
  rep(i,h){
    rep(j,w){
      if(f[i][j]=='.'){
        a.y=i;
        a.x=j;
        found=true;
        break;
      }
    }
    if(found) break;
  }
  //ここからBFS
  queue<point> que;
  que.push(a);
  f[a.y][a.x]='a';
  while (!que.empty()){
    point v=que.front();
    que.pop();
    rep(i,4){
      int nx=v.x+dx[i], ny=v.y+dy[i];
      if(0<=nx&&nx<w && 0<=ny&&ny<h && f[ny][nx]=='.'){
        f[ny][nx]='a';
        point tmp;
        tmp.x=nx;
        tmp.y=ny;
        que.push(tmp);
      }
    }
  }

  //次に見つかった点
  point b;
  found=false;
  rep(i,h){
    rep(j,w){
      if(f[i][j]=='.'){
        b.y=i;
        b.x=j;
        found=true;
        break;
      }
    }
    if(found) break;
  }
  //ここからBFS
  que.push(b);
  f[b.y][b.x]='b';
  while (!que.empty()){
    point v=que.front();
    que.pop();
    rep(i,4){
      int nx=v.x+dx[i], ny=v.y+dy[i];
      if(0<=nx&&nx<w && 0<=ny&&ny<h && f[ny][nx]=='.'){
        f[ny][nx]='b';
        point tmp;
        tmp.x=nx;
        tmp.y=ny;
        que.push(tmp);
      }
    }
  }

  /*
  printf("\n");
  rep(i,h) cout<<f[i]<<endl;
  printf("\n");
  */

  //aの位置から#上を辿ってbに辿り着く距離をそれぞれのaにおいて計算
  const int INF=10000000;
  int ans=INF;
  for(int Y=0; Y<h; ++Y){
    for(int X=0; X<w; ++X){
      if(f[Y][X]!='a') continue;

      int d[20][20];
      rep(i,20)rep(j,20) d[i][j]=INF;
      d[Y][X]=0;

      queue<point> q;
      point st;
      st.x=X;
      st.y=Y;
      q.push(st);
      while(!q.empty()){
        point v=q.front();
        q.pop();
        rep(i,4){
          int nx=v.x+dx[i], ny=v.y+dy[i];
          if(0<=nx&&nx<w && 0<=ny&&ny<h && f[ny][nx]!='a' && d[ny][nx]>d[v.y][v.x]+1){

            d[ny][nx]=d[v.y][v.x]+1;
            if(f[ny][nx]=='b'){
              ans=min(ans,d[ny][nx]-1);
              //printf("%d, %d %d\n",ans,ny,nx);
            }
            else{
              point tmp;
              tmp.x=nx;
              tmp.y=ny;
              q.push(tmp);
            }
          }
        }
      }

    }
  }

  std::cout << ans << std::endl;
  return 0;
}
