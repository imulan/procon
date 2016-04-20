#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int n,k;
  cin >>n >>k;

  //太郎君、次郎君がそれぞれ出す目の合計の確率
  double p[61],q[61];

  rep(i,61){
    p[i]=0;
    q[i]=0;
  }

  //次郎君の方は普通に計算
  q[0]=1;
  rep(i,n){ //サイコロの個数
    double tmp[61];
    rep(j,61) tmp[j]=0;

    rep(j,61){
      for(int k=1;k<=6;++k){
        tmp[j+k]+=q[j]/6.0;
      }
    }

    rep(j,61) q[j]=tmp[j];
  }

  //rep(i,61) printf("%2d: %.10lf\n",i,q[i]);

  //太郎君はk個と(n-k)個に分けて計算
  p[0]=1;
  //先に普通のサイコロ(n-k)個ぶん
  rep(i,n-k){ //サイコロの個数
    double tmp[61];
    rep(j,61) tmp[j]=0;

    rep(j,61){
      for(int k=1;k<=6;++k){
        tmp[j+k]+=p[j]/6.0;
      }
    }

    rep(j,61) p[j]=tmp[j];
  }
  //次にイカサマなサイコロk個ぶん
  rep(i,k){ //サイコロの個数
    double tmp[61];
    rep(j,61) tmp[j]=0;

    rep(j,61){
      for(int k=4;k<=6;++k){
        tmp[j+k]+=p[j]/3.0;
      }
    }

    rep(j,61) p[j]=tmp[j];
  }

  double ans=0;
  rep(i,61){//次郎君の出したサイコロの和
    for(int j=i+1; j<=60; ++j) ans+=q[i]*p[j];
  }


  printf("%.10lf\n", ans);
  return 0;
}
