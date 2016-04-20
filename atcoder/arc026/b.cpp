#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

//約数の和
ll div(ll n){
  ll ret=1;
  for(ll i=2; i*i<=n; ++i){
    ll add=1;
    ll now=i;
    while(n%i==0){
      n/=i;
      add+=now;
      now*=i;
    }
    ret*=add;
  }
  if(n>1) ret*=n+1;
  return ret;
}

int main(int argc, char const *argv[]) {
  ll n;
  cin >>n;

  //printf(" %lld - %lld\n",div(n),n);
  ll r=div(n)-n;

  string ans="Perfect";
  if(r<n) ans="Deficient";
  else if(r>n) ans="Abundant";
  std::cout << ans << std::endl;
  return 0;
}
