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
  int n;
  cin >>n;
  int ans=0;
  REP(i,n){
    int H,M,h,m;
    scanf(" %d:%d %d:%d",&H,&M,&h,&m);

    int x=H*60+M, y=h*60+m;
    int tmp;

    if(x>y) tmp=24*60-(x-y);
    else tmp=y-x;

    //printf(" %d\n",tmp);

    ans+=tmp;
  }
  std::cout << ans << std::endl;
  return 0;
}
