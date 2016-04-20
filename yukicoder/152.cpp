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

long gcd(long p, long q){
  if(p<q) swap(p,q);

  while(q!=0){
    long tmp=q;
    q=p%q;
    p=tmp;
  }

  return p;
}

int main(int argc, char const *argv[]) {
  long L;
  const int mod = 1000003;

  cin >>L;

  int ans=0;
  for(long m=2; m<=3500; ++m){
    for(long n=1; n<m; ++n){
      if((m-n)%2==0 || gcd(m,n)>1) continue;

      if(8*m*(m+n)<=L) ++ans;
    }
    ans%=mod;
  }

  std::cout << ans << std::endl;
  return 0;
}
