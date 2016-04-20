#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll ab(ll p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  long b;
  int n;
  cin >>b >>n;

  std::vector<ll> c(n);
  ll sum=0;
  rep(i,n){
    cin >>c[i];
    sum += c[i];
  }


  ll ans=sum;
  long left=0, right=(sum+b)/n;
  ll tmp=0;
  rep(i,n) tmp+=ab(c[i]-right);
  ans=min(ans,tmp);

  bool end=false;
  while (right>left) {
    //printf("  interval  %ld %ld\n",left,right);
    //ちょっと早めにうち切る
    if(right-left<10) break;

    long xl=(left*2+right)/3;
    long xr=(left+right*2)/3;

    ll tl=0, tr=0;
    rep(i,n) tl+=ab(c[i]-xl);
    rep(i,n) tr+=ab(c[i]-xr);

    if(tl>=tr) left=xl;
    if(tl<=tr) right=xr;
  }

  //絞った所を全探索
  for(long i=left; i<=right; ++i){
    ll tmp=0;
    rep(j,n) tmp+=ab(c[j]-i);
    ans=min(ans,tmp);
  }

  std::cout << ans << std::endl;
  return 0;
}
