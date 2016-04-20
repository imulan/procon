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

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  std::vector<int> d(n);

  int a=0,longest=0;

  REP(i,n){
    cin >>d[i];
    a+=d[i];
    longest=max(longest,d[i]);
  }

  int b=longest-(a-longest);
  if(b<0) b=0;

  printf("%d\n%d\n",a,b);

  return 0;
}
