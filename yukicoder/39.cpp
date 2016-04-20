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

  string n;
  cin >>n;

  long ans=atol(n.c_str());
  rep(i,n.size()){
    rep(j,n.size()){
      string t=n;
      swap(t[i],t[j]);
      ans=max(ans,atol(t.c_str()));
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
