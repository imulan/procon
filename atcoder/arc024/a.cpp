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
  int L,R;
  cin >>L >>R;
  std::vector<int> l(L),r(R);
  REP(i,L) cin >>l[i];
  REP(i,R) cin >>r[i];

  sort(l.begin(),l.end());
  sort(r.begin(),r.end());

  int x=0,y=0;
  int ans=0;
  while(x<L && y<R){
    if(l[x]<r[y]) ++x;
    else if(l[x]>r[y]) ++y;
    else{
      ++ans;
      ++x;
      ++y;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
