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
  ll r,c;
  cin >>r >>c;

  ll ans=0;
  if(r!=c){
    if(r%2==0 || c%2==0) ans=r*c/2-1;
    else ans=r*c/2;
  }
  else{
    if(r%2==0){
      ans=(r/2)*(c/2)-1;
    }
    else{
      ll t=r/2;
      ans=t*t+t;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
