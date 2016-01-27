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
  int r,c,d;
  cin >>r >>c >>d;

  vector< vector<int> > a(r, vector<int>(c));
  REP(i,r){
    REP(j,c){
      cin >>a[i][j];
    }
  }

  int dd=d%2;
  int ans=0;
  REP(i,r){
    REP(j,c){
      if((i+j)<=d && (i+j)%2==dd){
        ans = max(ans,a[i][j]);
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
