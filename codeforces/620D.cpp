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

ll ab(ll p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int n,m;
  ll sa=0, sb=0;

  cin >>n;
  std::vector<long> a(n);
  REP(i,n){
    scanf(" %ld", &a[i]);
    sa+=a[i];
  }
  cin >>m;
  std::vector<long> b(m);
  REP(i,m){
    scanf(" %ld", &b[i]);
    sb+=b[i];
  }



  return 0;
}
