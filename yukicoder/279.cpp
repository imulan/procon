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
  string s;
  cin >>s;

  int t=0, r=0, e=0;
  REP(i,s.size()){
    if(s[i]=='t') ++t;
    else if(s[i]=='r') ++r;
    else if(s[i]=='e') ++e;
  }

  cout << min(e/2,min(t,r)) << endl;

  return 0;
}
