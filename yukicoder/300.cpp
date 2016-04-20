#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

bool prime(ll n){
  bool ret=true;
  for(ll i=2; i*i<=n; ++i){
    if(n%i==0){
      ret=false;
      break;
    }
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  ll x;
  cin >>x;

  ll ans=1;
  if(prime(x)) ans=x;
  else{
    ll t=x;
    for(ll i=2; i*i<=x; ++i){
      if(x%i==0 && prime(i)){
        //printf(" %lld\n",i);

        ll ct=0;
        while(t%i==0){
          t/=i;
          ++ct;
        }

        if(ct%2==1) ans*=i;
      }
    }

    if(prime(t)) ans*=t;
  }

  std::cout << ans << std::endl;
  return 0;
}
