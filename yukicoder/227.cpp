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
  int c[14]={0};
  REP(i,5){
    int a; cin >>a;
    ++c[a];
  }

  string ans="NO HAND";

  bool three=false;
  REP(i,14){
    if(c[i]==3) three=true;
  }

  if(three){
    bool fu=false;
    REP(i,14){
      if(c[i]==2) fu=true;
    }

    if(fu) ans="FULL HOUSE";
    else ans="THREE CARD";
  }
  else{
    int ct=0;
    REP(i,14){
      if(c[i]==2) ++ct;
    }

    if(ct==2) ans="TWO PAIR";
    else if(ct==1) ans="ONE PAIR";
  }

  std::cout << ans << std::endl;
  return 0;
}
