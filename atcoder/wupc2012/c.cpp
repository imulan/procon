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

const int INF=1000000000;

int n,m;
string s[500];

int dist(const pii &a, const pii &b){
  int i;

  int df[4]={1,-1,0,0};
  int ds[4]={0,0,1,-1};

  //BFS
  int d[500][500];
  fill(d[0],d[500],INF);
  d[a.fi][a.sc]=0;
  queue<pii> que;
  que.push(a);
  while (!que.empty()){
    pii v=que.front();
    que.pop();
    rep(i,4){
      int nf=v.fi+df[i], ns=v.sc+ds[i];
      if(0<=nf&&nf<n && 0<=ns&&ns<m){
        if(s[nf][ns]!='#' && d[nf][ns]>d[v.fi][v.sc]+1){
          d[nf][ns]=d[v.fi][v.sc]+1;
          que.push(pii(nf,ns));
        }
      }
    }
  }

  return d[b.fi][b.sc];
}

int main(int argc, char const *argv[]) {
  int i,j;

  cin >>n >>m;
  rep(i,n) cin >>s[i];

  pii start,computer,goal;
  rep(i,n){
    rep(j,m){
      if(s[i][j]=='S') start=pii(i,j);
      if(s[i][j]=='C') computer=pii(i,j);
      if(s[i][j]=='G') goal=pii(i,j);
    }
  }

  int t1=dist(start,computer);
  int t2=dist(computer,goal);

  int ans=t1+t2;
  if(t1==INF || t2==INF) ans=-1;
  std::cout << ans << std::endl;
  return 0;
}
