#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const ll mod=1000003;

int main(int argc, char const *argv[]) {
  int i,j;

  ll x;
  int n;
  cin >>x >>n;
  std::vector<int> a(n);
  rep(i,n) cin >>a[i];

  ll pw[31];
  pw[0]=x;
  rep(i,30) pw[i+1]=(pw[i]*pw[i])%mod;

  ll ans=0;
  rep(i,n){
    ll tmp=1;
    rep(j,31){
      if((a[i]>>j)&1){
        tmp*=pw[j];
        tmp%=mod;
        //printf(" tmp =%lld\n", tmp);
      }
    }
    ans+=tmp;
    ans%=mod;
  }

  std::cout << ans << std::endl;
  return 0;
}
