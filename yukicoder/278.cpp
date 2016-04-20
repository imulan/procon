#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll sum(ll n){
  ll i;

  ll ret=1;
  ll t=n;
  for(i=2; i*i<=n; ++i){
    if(t%i==0){
      ll r=1;
      ll ad=1;
      while(t%i==0){
        t/=i;
        ad*=i;
        r+=ad;
      }
      /*
      cout <<"ad= "<<ad <<endl;
      cout <<"r= "<<r <<endl;
      */
      ret*=r;
    }
  }

  if(t>1) ret*=(1+t);
  return ret;
}

int main(int argc, char const *argv[]) {
  ll n;
  cin >>n;
  if(n%2==0) n/=2;
  cout << sum(n) << endl;
  return 0;
}
