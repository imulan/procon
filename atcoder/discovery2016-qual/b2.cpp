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
  int n;
  cin >>n;
  vector<int> a(n),s(n);
  REP(i,n){
    scanf(" %d", &a[i]);
    s[i]=a[i];
  }
  sort(s.begin(),s.end());

  int inf=114514;
  int ans=0;
  int now=0; //s_index

  if(s[now]==a[0]) ++now;

  while(1){
    ++ans;
    for(int i=1; i<n; ++i){
      if(s[now]==a[i]){
        ++now;
      }
    }

    if(s[now]==a[0]) ++now;

    if(now==n) break;
  }

  std::cout << ans << std::endl;
  return 0;
}
