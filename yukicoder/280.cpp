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
  int i;
  int n;
  cin >>n;
  std::vector<ll> z(n);
  rep(i,n) cin >>z[i];
  std::cout << z[n-1]<<"/"<<z[0] << std::endl;
  return 0;
}
