#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pii;

const ll INF=10000000000000;

//(現在の位置、雪だるまの大きさ)
ll dp[50][50][2501];

int main(int argc, char const *argv[]) {
  int i;

  int df[4]={1,-1,0,0};
  int ds[4]={0,0,1,-1};

  int h,w,a,b;
  pii s,g;
  //input
  cin >>h >>w;
  cin >>a >>s.fi >>s.sc;
  cin >>b >>g.fi >>g.sc;
  vector<string> m(h);
  rep(i,h) cin >>m[i];

  fill(dp[0][0],dp[50][0],INF);
  dp[s.fi][s.sc][a]=0;

  queue<pair<pii,int>> que;
  que.push(pair<pii,int>(s,a));
  while(!que.empty()){
    pair<pii,int> v=que.front();
    que.pop();

    //四方に進んでみる
    rep(i,4){
      int nf=v.fi.fi+df[i];
      int ns=v.fi.sc+ds[i];
      int z=v.sc;

      if(0<=nf&&nf<h&&0<=ns&&ns<w){
        if(m[nf][ns]=='*'){
          if(z<2500 && dp[nf][ns][z+1]>dp[v.fi.fi][v.fi.sc][v.sc]+1){
            dp[nf][ns][z+1]=dp[v.fi.fi][v.fi.sc][v.sc]+1;
            que.push(pair<pii,int>(pii(nf,ns),z+1));
          }
        }
        else{
          if(z>1 && dp[nf][ns][z-1]>dp[v.fi.fi][v.fi.sc][v.sc]+1){
            dp[nf][ns][z-1]=dp[v.fi.fi][v.fi.sc][v.sc]+1;
            que.push(pair<pii,int>(pii(nf,ns),z-1));
          }
        }
      }
    }
  }

  string ans="No";
  if(dp[g.fi][g.sc][b]<INF) ans="Yes";
  std::cout << ans << std::endl;
  return 0;
}
