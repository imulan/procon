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
  long n;
  cin >>n;

  vector< pair<ll,ll> > p(n);
  map< pair<ll,ll>, long> mp;

  for(long i=0; i<n; ++i){
    scanf(" %I64d %I64d", &p[i].first, &p[i].second);
    mp[p[i]]=i+1;
  }

  sort(p.begin(), p.end());
  /*
  for(long i=0; i<n; ++i){
    printf(" %ld %ld\n", p[i].first, p[i].second);
  }
  */

  long index=-1;
  for(long i=2; i<n; ++i){
    ll p1=(p[1].second-p[0].second)*(p[i].first-p[0].first);
    ll p2=(p[i].second-p[0].second)*(p[1].first-p[0].first);
    if(p1==p2) continue;
    else{
      index=i;
      break;
    }
  }

  printf("%ld %ld %ld\n",mp[p[0]], mp[p[1]], mp[p[index]]);

  return 0;
}
