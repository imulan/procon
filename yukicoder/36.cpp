#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll div(ll n){
  ll ret=1;
  ll t=n;
  for(ll i=2; i*i<=n; ++i){
    ll ct=0;
    while (t%i==0) {
      t/=i;
      ++ct;
    }
    ret*=ct+1;
  }

  return ret;
}

int main(int argc, char const *argv[]) {
  ll n;
  cin >>n;

  //printf("  %lld\n", div(n));
  bool ans=true;
  if(div(n)<=3) ans=false;

  string r="NO";
  if(ans) r="YES";
  std::cout << r << std::endl;
  return 0;
}
