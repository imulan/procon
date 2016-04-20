#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  int n;
  cin >>n;
  vector<long> x(n),y(n);
  rep(i,n) cin >>x[i] >>y[i];

  ll p=0,q=0,r=0;

  double eps=1e-10;
  rep(i,n){//点B固定
    vector<double> arg;
    rep(j,n){
      if(i!=j) arg.pb(atan2(y[j]-y[i],x[j]-x[i]));
    }
    //偏角でソート
    sort(arg.begin(),arg.end());

    //2周分配列を用意しておく
    rep(j,n-1) arg.pb(arg[j]+2*M_PI);

    //しゃくとり法
    int a=0,b=0;
    rep(j,n-1){//点Aに対して
      //90度未満の部分を探す
      while(arg[a]-arg[j]<M_PI/2-eps) ++a;
      //180度未満
      while(arg[b]-arg[j]<M_PI-eps) ++b;

      //直角判定
      if(fabs(arg[a]-arg[j])<M_PI/2+eps){
        ++q;
        ++a;
      }

      r+=b-a;
    }
  }

  p=(ll)n*(n-1)*(n-2)/6 -q -r;

  printf("%lld %lld %lld\n",p,q,r);
  return 0;
}
