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

  std::vector<int> a(n);
  REP(i,n) cin >>a[i];

  int score[101]={0};
  REP(i,n){
    int b;
    cin >>b;
    score[b]+=a[i];
  }

  int m=0;
  for(int i=1; i<=100; ++i) m=max(m,score[i]);

  string ans="NO";
  if(score[0]>=m) ans="YES";

  std::cout << ans << std::endl;
  return 0;
}
