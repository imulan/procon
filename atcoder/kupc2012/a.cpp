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

  int n,t,e;
  cin >>n >>t >>e;
  vector<int> x(n);
  rep(i,n) cin >>x[i];

  int ans=-1;
  rep(i,n){
    bool v=false;
    v|=((t-e)%x[i]==0 || (t+e)%x[i]==0);
    v|=((t+e)/x[i]>(t-e)/x[i]);

    if(v){
      ans=i+1;
      break;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
