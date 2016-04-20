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

int main(int argc, char const *argv[]) {
  int df[4]={1,-1,0,0}, ds[4]={0,0,1,-1};

  while(1){
    int i,j;

    int w,h,p;
    cin >>w >>h >>p;
    if(w==0) break;

    //高さ
    int z[20][20];
    rep(i,h)rep(j,w) scanf(" %d",&z[i][j]);

    //水が来るかどうか
    int f[20][20]={0};

    for(int points=0; points<p; ++points){
      pi st;
      scanf(" %d %d", &st.sc, &st.fi);

      f[st.fi][st.sc]=1;
      queue<pi> que;
      que.push(st);
      while(!que.empty()){
        pi v=que.front();
        que.pop();
        rep(i,4){
          int nf=v.fi+df[i];
          int ns=v.sc+ds[i];
          if(0<=nf&&nf<h && 0<=ns&&ns<w){
            if(z[v.fi][v.sc]>z[nf][ns]){
              f[nf][ns]=1;
              que.push(pi(nf,ns));
            }
          }
        }
      }
    }

    int ans=0;
    rep(i,h)rep(j,w) ans+=f[i][j];
    std::cout << ans << std::endl;
  }
  return 0;
}
