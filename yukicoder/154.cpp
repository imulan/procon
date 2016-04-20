//BRの後にWが来てはいけないとか、もっと考えないとダメ

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
  int t;
  cin >>t;
  REP(T,t){
    string s;
    cin >>s;

    int g=0,r=0,w=0;
    bool v=true;
    REP(i,s.size()){
      if(s[i]=='G') ++g;
      else if(s[i]=='R') ++r;
      else ++w;

      if(r>g){
        v=false;
        break;
      }
    }

    if(g!=r) v=false;
    else{
      if(g==0) v=false;
      if(g>w) v=false;
    }
    string ans="possible";
    if(!v) ans="im"+ans;
    std::cout << ans << std::endl;
  }
  return 0;
}
