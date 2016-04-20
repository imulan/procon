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
  int n;
  cin >>n;

  vector< vector<string> > a(n,vector<string>(n));
  REP(i,n){
    REP(j,n){
      cin >>a[i][j];
    }
  }

  int ans=-1;
  REP(i,n){
    bool renchon=true;

    REP(j,n){
      if(i==j) continue;
      if(a[j][i]!="nyanpass") renchon = false;
    }

    if(renchon){
      if(ans==-1){
        ans=i+1;
      }
      else{
        ans=-1;
        break;
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
