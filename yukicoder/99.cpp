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

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  int e=0,o=0;
  REP(i,n){
    int a;
    scanf(" %d",&a);

    a=ab(a);
    if(a%2==0) ++e;
    else ++o;
  }

  int m=min(e,o);
  std::cout << n-m*2 << std::endl;
  return 0;
}
