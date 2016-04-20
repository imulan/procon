#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  int n;
  cin >>n;
  std::vector<int> a(n);
  rep(i,n) cin >>a[i];

  const int N=40000;
  bool dp[N];
  rep(i,N) dp[i]=false;
  dp[0]=true;

  rep(i,n){
    rep(j,N){
      if(dp[j]) dp[j^a[i]]=true;
    }
  }

  int ans=0;
  rep(j,N) if(dp[j]) ++ans;

  std::cout << ans << std::endl;
  return 0;
}
