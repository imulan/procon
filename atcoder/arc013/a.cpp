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
  int i;

  int a[3],b[3];
  rep(i,3) cin >>a[i];
  rep(i,3) cin >>b[i];

  sort(b,b+3);

  int ans=0;

  do{
    int r=1;
    rep(i,3) r*=a[i]/b[i];
    ans=max(ans,r);
  }while(next_permutation(b,b+3));

  std::cout << ans << std::endl;
  return 0;
}
