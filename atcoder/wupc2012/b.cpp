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
  int i,j;

  int n;
  cin >>n;
  vector<string> s(n);
  rep(i,n) cin >>s[i];

  string ans=s[0]+s[1];
  rep(i,n){
    rep(j,n){
      if(i==j) continue;
      if(ans>s[i]+s[j]) ans=s[i]+s[j];
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
