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
  int num[10]={0};
  int n;
  cin >>n;

  int ct=0;
  REP(i,n){
    int a[4];
    string s;

    REP(j,4) cin >>a[j];
    cin >>s;

    if(s=="NO"){ //この4つのどれでもない
      REP(j,4) num[a[j]]=-1;
    }
    else{ //この4つのうちどれか
      REP(j,4){
        if(num[a[j]]!=-1) ++num[a[j]];
      }
      ++ct;
    }
  }

  int ans=-1;
  REP(i,10){
    if(num[i]==ct){
      ans=i;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
