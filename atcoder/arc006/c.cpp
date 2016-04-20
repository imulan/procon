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

  //積み上げていく
  vector<int> v;

  rep(i,n){
    int w;
    scanf(" %d",&w);

    auto pos=lower_bound(v.begin(),v.end(),w);

    if(pos==v.end()) v.pb(w);
    else v[pos-v.begin()]=w;
    sort(v.begin(),v.end());
    /*
    rep(j,v.size()) printf(" %d", v[j]);
    printf("\n");
    */
  }

  std::cout << v.size() << std::endl;
  return 0;
}
