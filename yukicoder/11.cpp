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
  ll i;

  ll w,h,n;
  cin >>w >>h >>n;

  int m[1000001]={0};
  set<ll> s;

  rep(i,n){
    ll mark,num;
    cin >>mark >>num;

    s.insert(num);
    ++m[mark];
  }

  ll ans=0;
  for(i=1; i<=w; ++i){
    if(m[i]==0) ans+=s.size();
    else ans+=h-m[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
