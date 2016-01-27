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

//最小値,時刻iに位置jにいるとき
ll dp[2001][2001];
const ll INF=((ll)(1)<<62);

ll ab(ll p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  for(int i=0; i<=2000; ++i)
  for(int j=0; j<=2000; ++j)
  dp[i][j]=0;

  int N,L;
  cin >>N >>L;

  std::vector<int> T(N+1),p(N);
  REP(i,N) scanf(" %d %d", &T[i], &p[i]);
  T[N]=-1;

  int t_in=0;
  for(int t=1; t<=T[N-1]; ++t){

    //この時刻にある花火の数
    int ct=0;
    while (T[t_in+ct]==t) {
      ++ct;
    }
    //printf("t_in = %d,t= %d, ct= %d\n",t_in, t, ct);

    if(ct==0){//進まないのが最善
      REP(x,L+1){
        dp[t][x]=dp[t-1][x];
      }
    }
    else{
      ll m=dp[t-1][0];

      REP(x,L+1){
        m=min(m,dp[t-1][x]);
        dp[t][x]=m;
        for(int i=t_in; i<t_in+ct; ++i){
          dp[t][x]+=ab(x-p[i]);
        }
      }

    }

    t_in+=ct;
  }
  /*
  for(int i=1; i<=T[N-1]; ++i){
    for(int j=0; j<=L; ++j){
      std::cout << " " <<  dp[i][j];
    }
    cout << endl;
  }
  */
  ll ans=INF;
  REP(i,L+1) ans=min(ans,dp[T[N-1]][i]);

  cout << ans << endl;
  return 0;
}
