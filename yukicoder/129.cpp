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

int mod=1e9;
int c[10001][10001]={0};

int main(int argc, char const *argv[]) {
  REP(i,10001) c[i][0]=c[i][i]=1;

  for(int i=2; i<=10000; ++i){
    for(int j=1; j<i; ++j){
      c[i][j]=c[i-1][j-1]+c[i-1][j];
      c[i][j]%=mod;
    }
  }

  ll n,m;
  cin >>n >>m;

  ll bill=n/1000;
  ll per=bill/m;

  ll r=bill-per*m;

  std::cout << c[m][r] << std::endl;
  return 0;
}
