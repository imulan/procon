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
  int L,N;
  cin >>L >>N;
  vector<int> w(N);
  for(int i=0; i<N; ++i) cin >>w[i];

  sort(w.begin(),w.end());

  int ans=0;
  int now=0;
  for(int i=0; i<N; ++i){
    if(now+w[i]>L) break;

    ++ans;
    now+=w[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
