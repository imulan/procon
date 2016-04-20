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
  int w;
  cin >>w;

  string s="?DiscoPresentsDiscoveryChannelProgrammingContest2016";

  bool end=false;
  for(int i=1; i<s.size(); ++i){
    cout << s[i];
    if(i%w==0){
      end=true;
      cout << endl;
    }
    else end=false;
  }

  if(!end) cout << endl;
  return 0;
}
