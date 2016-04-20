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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int n,m,k;
  cin >>n >>m >>k;

  std::vector<ll> a(n),b(m);
  ll sa=0, sb=0;

  REP(i,n){
    cin >>a[i];
    sa+=a[i];
  }
  REP(i,m){
    cin >>b[i];
    sb+=b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans=0;
  if(k==1){
    REP(i,n){
      REP(j,m){
        ans=max(ans,(sa-a[i]+b[j])*(sb-b[j]+a[i]));
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
