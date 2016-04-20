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
  ll n;
  cin >>n;

  ll ans=n;

  for(ll i=3; i*i<=n; ++i){
    if(n%i==0){
      ans=i;
      break;
    }
  }

  if(ans==n && ans%2==0 && ans>4) ans/=2;

  std::cout << ans << std::endl;
  return 0;
}
