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
  ll a,b,c,d;
  cin >>a >>b >>c >>d;

  ll A=a*c-b*b;
  ll B=b*c-a*d;
  ll C=b*d-c*c;

  string ans="I";
  if(B*B-4*A*C>=0) ans="R";
  std::cout << ans << std::endl;

  return 0;
}
