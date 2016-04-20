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
  long i;

  long n;
  cin >>n;
  vector<long> p(n);
  rep(i,n) cin >>p[i];
  string s;
  cin >>s;

  ll ans=0;
  rep(i,n){
    if(s[i]=='B') ans+=p[i];
  }

  vector<ll> pr(n+1),su(n+1);

  pr[0]=0;
  rep(i,n){
    if(s[i]=='A') pr[i+1]=pr[i]+p[i];
    else pr[i+1]=pr[i]-p[i];
  }

  su[n]=0;
  for(i=n; i>0; --i){
    if(s[i-1]=='A') su[i-1]=su[i]+p[i-1];
    else su[i-1]=su[i]-p[i-1];
  }

  ll m=0;
  rep(i,n+1) m=max(m,max(pr[i],su[i]));

  std::cout << ans+m << std::endl;
  return 0;
}
