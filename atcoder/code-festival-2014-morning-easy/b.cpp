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
  int n;
  cin >>n;
  --n;

  int ans;
  if(n%40<20) ans=n%20;
  else ans=19-n%20;

  std::cout << ans+1 << std::endl;
  return 0;
}
