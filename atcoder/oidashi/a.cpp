#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pi;
const int INF=10000000;

int main(int argc, char const *argv[]) {
  int i,j,k;
  int df[4]={1,-1,0,0}, ds[4]={0,0,1,-1};

  int h,w;
  cin >>h >>w;
  vector<string> f(h);
  rep(i,h) cin >>f[i];

  pi s,g;
  rep(i,h)rep(j,w){
    if(f[i][j]=='S'){
      s=pi(i,j);
      f[i][j]='o';
    }
    if(f[i][j]=='G'){
      g=pi(i,j);
      f[i][j]='x';
    }
  }

  queue<pi> que;

  //スタートからBFS
  int dis[300][300];
  fill(dis[0],dis[300],INF);
  dis[s.fi][s.sc]=0;
  que.push(s);
  while(!que.empty()){
    pi v=que.front();
    que.pop();
    rep(k,4){
      int nf=v.fi+df[k];
      int ns=v.sc+ds[k];
      if(0<=nf&&nf<h && 0<=ns&&ns<w){
        if(f[nf][ns]!='#' && dis[nf][ns]>dis[v.fi][v.sc]+1){
          f[nf][ns]='o';
          dis[nf][ns]=dis[v.fi][v.sc]+1;
          que.push(pi(nf,ns));
        }
      }
    }
  }

  //ゴールからBFS
  int dig[300][300];
  fill(dig[0],dig[300],INF);
  dig[g.fi][g.sc]=0;
  que.push(g);
  while(!que.empty()){
    pi v=que.front();
    que.pop();
    rep(k,4){
      int nf=v.fi+df[k];
      int ns=v.sc+ds[k];
      if(0<=nf&&nf<h && 0<=ns&&ns<w){
        if(f[nf][ns]!='#' && dig[nf][ns]>dig[v.fi][v.sc]+1){
          f[nf][ns]='x';
          dig[nf][ns]=dig[v.fi][v.sc]+1;
          que.push(pi(nf,ns));
        }
      }
    }
  }

  int ans=0;
  rep(i,h)rep(j,w){
    if(f[i][j]!='#') continue;

    //スタート・ゴールとのそれぞれの隣接判定
    bool oo=false;
    bool xx=false;
    int doo=INF,dxx=INF;
    rep(k,4){
      int nf=i+df[k];
      int ns=j+ds[k];
      if(0<=nf&&nf<h && 0<=ns&&ns<w){
        if(f[nf][ns]=='o'){
          oo=true;
          doo=min(doo,dis[nf][ns]);
        }
        if(f[nf][ns]=='x'){
          xx=true;
          dxx=min(dxx,dig[nf][ns]);
        }
      }
    }

    if(oo && xx) ans=max(ans,doo+dxx+2);
  }

  std::cout << ans << std::endl;
  return 0;
}
