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
  bool prime[1000001];
  rep(i,1000001) prime[i]=true;
  prime[0]=prime[1]=false;
  for(int i=2; i<=1000000; ++i){
    if(prime[i]){
      for(int j=2; i*j<=1000000; ++j)
        prime[i*j]=false;
    }
  }

  //素数リスト
  vector<int> p;
  rep(i,1000000) if(prime[i]) p.pb(i);

  int n;
  double q;
  cin >>n >>q;

  double pw[1000];
  pw[0]=1;
  rep(i,999){
    pw[i+1]=pw[i]*(1-q);
    //printf("pw[%d]=%.40lf\n",i+1,pw[i+1] );
  }

  double ans=0.0;
  for(int i=2; i<=n; ++i){
    if(prime[i]) ans+=1.0;
    else{
      //約数の個数を数える
      int t=i;
      int j,c=1;
      for(int k=2; k*k<=t; ++k,c*=j){
        for(j=1; !(t%k); ++j){
          t/=k;
        }
      }
      if(1<t) c*=2;

      //printf(" %d: %d\n", i, c);
      ans+=pw[c-2];
    }
  }

  printf("%.10lf\n", ans);
  return 0;
}
