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

  map<int,int> mp;
  REP(i,n){
    int a;
    scanf(" %d", &a);

    if(mp.find(a)==mp.end()){
      mp[a]=1;
    }
    else ++mp[a];
  }

  int ans=0;
  foreach(it,mp){
    if(it->second==1) ++ans;
  }

  std::cout << ans << std::endl;
  return 0;
}
