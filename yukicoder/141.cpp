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
  ll m,n;
  cin >>m >>n;

  ll ans=0;

  while(1){
    // m/nが1以下になるまで減らす
    ll t=m/n;
    if(m%n==0) --t;

    ans+=t;
    m-=t*n;
    if(m==n) break;

    //ひっくり返す
    swap(m,n);
    ++ans;

    //printf("(m,n)=(%lld,%lld)\n",m,n);
  }

  std::cout << ans << std::endl;
  return 0;
}
