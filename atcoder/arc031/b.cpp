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

int df[4]={1,-1,0,0},ds[4]={0,0,1,-1};

int main(int argc, char const *argv[]) {
  int i,j,k,x,y;

  string a[10];
  rep(i,10) cin >>a[i];

  //BFSスタート位置
  pi st;

  rep(i,10){
    rep(j,10){
      if(a[i][j]=='o'){
        st.fi=i;
        st.sc=j;
        i=j=10;
      }
    }
  }

  bool v=false;
  rep(i,10){
    rep(j,10){
      if(a[i][j]=='o') continue;

      string b[10];
      rep(k,10) b[k]=a[k];
      b[i][j]='o';

      //BFS
      queue<pi> que;
      que.push(st);
      b[st.fi][st.sc]='A';
      while(!que.empty()){
        pi v=que.front();
        que.pop();
        rep(k,4){
          int nf=v.fi+df[k];
          int ns=v.sc+ds[k];
          if(0<=nf&&nf<10&&0<=ns&&ns<10 && b[nf][ns]=='o'){
            b[nf][ns]='A';
            que.push(pi(nf,ns));
          }
        }
      }

      v=true;
      rep(x,10){
        rep(y,10){
          if(b[x][y]=='o') v=false;
        }
      }

      if(v) i=j=10;
    }
  }



  string ans="NO";
  if(v) ans="YES";
  std::cout << ans << std::endl;

  return 0;
}
