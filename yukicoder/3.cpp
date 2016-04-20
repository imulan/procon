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

int ch(int p){
  int ret=0;
  for(int i=0; i<15; ++i) if(p>>i&1) ++ret;
  return ret;
}

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int i,j;

  int n;
  cin >>n;

  int dp[10001];
  rep(i,10001) dp[i]=INF;
  dp[1]=1;

  queue<int> que;
  que.push(1);

  while(!que.empty()){
    int v=que.front();
    que.pop();

    int t=ch(v);

    if(v-t>=1 && dp[v-t]>dp[v]+1){
      dp[v-t]=dp[v]+1;
      que.push(v-t);
    }
    if(v+t<=n && dp[v+t]>dp[v]+1){
      dp[v+t]=dp[v]+1;
      que.push(v+t);
    }
  }

  int ans=dp[n];
  if(ans==INF) ans=-1;
  std::cout << ans << std::endl;
  return 0;
}
