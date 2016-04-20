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
  ll L;
  cin >>n >>L;

  std::vector<ll> x(n+1),w(n),t(n);
  REP(i,n) cin >>x[i] >>w[i] >>t[i];
  //終端を追加
  x[n]=L;

  //最初の交差点まで普通に進む
  ll ans = x[0];

  REP(i,n){
    //交差点にさしかかる
    ll tt=ans/t[i];

    if(tt%2==1){//現在赤信号なので青になるまで待つ
      ans+=t[i]-(ans%t[i]);
    }
    else{//現在青信号なので赤になる前に渡りきれるか判定
      if(t[i]-(ans%t[i])<w[i]){//ムリなので次の青信号まで待つ
        ans+=t[i]*2-(ans%t[i]);
      }
    }
    //次の交差点まで進む
    ans+=x[i+1]-x[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
