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
  int aw,ab,bw,bb,c,d;
  cin >>aw >>ab >>bw >>bb >>c >>d;

  //まずAからBへc個、移す
  if(ab>=c){ //c個より黒が多ければ全部黒
    ab-=c;
    bb+=c;
  }
  else{ //白を(c-ab)個、黒をab個
    aw-=c-ab;
    bw+=c-ab;
    bb+=ab;
    ab=0;
  }

  //そしてBからAへD個、移す
  if(bw>=d){ //d個より白が多ければ全部白
    aw+=d;
    bw-=d;
  }
  else{ //白をbw個、黒を(d-bw)個
    ab+=d-bw;
    bb-=d-bw;
    aw+=bw;
    bw=0;
  }

  std::cout << aw << std::endl;
  return 0;
}
