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

  int n=s.size();

  std::vector<int> v(n);
  REP(i,n) v[i]=s[i]-'0';

  sort(v.begin(),v.end(),greater<int>());

  REP(i,n) printf("%d", v[i]);
  printf("\n");

  return 0;
}
