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

int main(int argc, char const *argv[]) {
  ll ch[26];
  REP(i,26) cin >>ch[i];

  ll ans=1;
  ans*=ch['h'-'a'];
  ans*=ch['e'-'a'];
  ans*=ch['w'-'a'];
  ans*=ch['r'-'a'];
  ans*=ch['d'-'a'];

  //oはなるべく均等にわけて並べるのが良い
  ll o=ch['o'-'a'];
  ll o_p=(o/2)*(o-o/2);
  ans*=o_p;

  //lはi*(i-1)*(l-i)/2を最大化出来る場所を探す
  ll l=ch['l'-'a'];
  ll l_p=0;
  for(ll i=2; i<l; ++i){
    l_p=max(l_p,i*(i-1)*(l-i)/2);
  }
  ans*=l_p;

  std::cout << ans << std::endl;
  return 0;
}
