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
  string s[2],pa,pb,xa,xb;
  cin >>s[0] >>pa >>xa >>s[1] >>pb >>xb;

  int ans=-1;
  if(pa.size()>pb.size()){
    ans=0;
  }
  else if(pa.size()<pb.size()){
    ans=1;
  }
  else{
    REP(i,pa.size()){
      if(pa[i]!=pb[i]){
        if(pa[i]>pb[i]) ans=0;
        else ans=1;

        break;
      }
    }
  }

  if(ans==-1) printf("-1\n");
  else cout << s[ans] << endl;

  return 0;
}
