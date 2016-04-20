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
  long i;

  long n;
  cin >>n;

  ll a=0,b=0;
  rep(i,n){
    ll t;
    cin >>t;
    a|=t;
  }
  rep(i,n){
    ll t;
    cin >>t;
    b|=t;
  }

  std::cout << a+b << std::endl;
  return 0;
}
