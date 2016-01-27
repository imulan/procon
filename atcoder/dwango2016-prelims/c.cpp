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
  int N,M,src,dst;

  cin >>N >>M >>src >>dst;

  vector<int> s[100000];
  vector<int> w[100000];
  REP(i,M){
    int L;
    scanf(" %d", &L);
    REP(j,L){
      int a;
      scanf(" %d", &a);
      s[i].push_back(a);
    }
    REP(j,L-1){
      int a;
      scanf(" %d", &a);
      w[i].push_back(a);
    }


  }

  return 0;
}
