#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

const ll mod=1e9+7;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  ll ans=0;
  REP(i,n){
    ll c,d;
    cin >>c >>d;

    ll a=((c/2)+(c%2))%mod;
    ll b=d%mod;

    ans+=a*b;
    ans%=mod;
  }

  std::cout << ans << std::endl;
  return 0;
}
