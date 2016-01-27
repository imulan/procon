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

const int mod=1e9+7;

int dp[5001][5001]={0};
int nxt[5001][5001]={0};


int main(int argc, char const *argv[]) {
  int n;
  string str;
  cin >>n >>str;

  std::vector<int> s(n+1);
  for(int i=1; i<=n; ++i) s[i]=str[i-1]-'0';

  //まずnxtを埋めておく
  for(int a=n; a>=1; --a){
    for(int b=n; b>a; --b){

    }
  }




  return 0;
}
