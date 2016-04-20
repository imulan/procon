#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  bool prime[10001];
  rep(i,10001) prime[i]=true;
  prime[0]=prime[1]=false;
  for(i=2;i<=10000;++i){
    if(prime[i]){
      for(j=2;i*j<=10000;++j) prime[i*j]=false;
    }
  }
  vector<int> p;
  rep(i,10001) if(prime[i]) p.pb(i);

  int n;
  cin >>n;

  bool dp[10001];
  rep(i,10001) dp[i]=false;
  dp[0]=dp[1]=true;

  for(i=3; i<=n; ++i){
    //どれか1つでも負けになるなら勝ち
    rep(j,p.size()){
      if(p[j]>i) break;
      if(!dp[i-p[j]]){
        dp[i]=true;
        break;
      }
    }
  }

  string ans=(dp[n])?"Win":"Lose";
  std::cout << ans << std::endl;
  return 0;
}
