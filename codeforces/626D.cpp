#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long i,j;

  long n;
  cin >>n;
  std::vector<long> a(n);
  rep(i,n) cin >>a[i];

  sort(a.begin(),a.end());

  //勝つときの差を列挙して場合の数をカウント
  ll ct[5000]={0};
  rep(i,n){
    rep(j,i){
      ++ct[a[i]-a[j]];
    }
  }

  //2勝するときの数の場合の数
  ll dp[10000]={0};
  rep(i,5000){
    rep(j,5000){
      dp[i+j]+=ct[i]*ct[j];
    }
  }

  double ans=0;
  //最後1回で前の2回分を取り返せる場合の数
  rep(i,5000){
    rep(j,i){
      ans+=(double)ct[i]*dp[j];
    }
  }

  ll N=n*(n-1)/2;
  printf("%.20lf\n",ans/N/N/N);
  return 0;
}
