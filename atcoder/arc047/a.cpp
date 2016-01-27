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
  int N,L;
  string s;

  cin >>N >>L;
  cin >>s;

  int ans=0;
  int now=1;
  REP(i,s.size()){
    if(s[i]=='+') ++now;
    else --now;

    if(now>L){
      now=1;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
