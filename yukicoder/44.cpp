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
  int n;
  cin >>n;

  ll dp[51];
  dp[0]=dp[1]=1;
  for(int i=2; i<=50; ++i) dp[i]=dp[i-1]+dp[i-2];

  cout << dp[n] << endl;
  return 0;
}
