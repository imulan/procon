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
  int n;
  cin >>n;
  vector<int> c(n);
  int s=0;
  REP(i,n){
    scanf(" %d", &c[i]);
    s+=c[i];
  }

  int ans=0;
  if(s==0||s==n) ans=-1;
  else{
    //色が連続している区間に分ける
    vector<int> seg;

    int now_c=c[0];
    int index=0;
    REP(i,n){
      if(c[i]!=now_c){
        //printf(" ch :%d\n", i);
        seg.push_back(i-index);
        index=i;
        now_c=c[i];
      }
    }
    seg.push_back(n-index);

    //円なので始点と終点の色が一致している場合は区間を連結
    if(c[0]==c[n-1]){
      seg[0]+=seg[seg.size()-1];
      seg.erase(seg.begin()+(seg.size()-1));
    }

    REP(i,seg.size()){
      ans = max(ans, (seg[i]+1)/2);
      //printf(" %d take %d\n", seg[i], (seg[i]+1)/2);
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
