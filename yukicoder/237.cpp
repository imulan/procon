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

  ll a;
  cin >>a;

  //フェルマー素数
  ll f[5]={3,5,17,257,65537};

  ll pw[31]={0};
  pw[0]=1;
  rep(i,30) pw[i+1]=pw[i]*2;

  ll ans=0;
  for(i=(1<<5)-1; i>=0; --i){
    //かけるべきフェルマー素数をビットで
    ll t=1;
    rep(j,5) if((i>>j)&1) t*=f[j];

    //かける2の累乗数
    for(j=0; t*pw[j]<=a; ++j);

    ans+=j;
  }

  std::cout << ans-2 << std::endl;
  return 0;
}
