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

  int n;
  cin >>n;
  std::vector<int> h(n);
  rep(i,n) scanf(" %d",&h[i]);

  std::vector<int> v;
  v.pb(0);
  int now=0;
  rep(i,n-1){
    if(h[i+1]-h[i]>0){
      if(now<0){
        v.pb(now);
        now=0;
      }
      ++now;
    }
    else{
      if(now>0){
        v.pb(now);
        now=0;
      }
      --now;
    }
  }
  if(now!=0) v.pb(now);
  v.pb(0);

  int ans=0;
  rep(i,(int)v.size()-1){
    if(v[i]>=0&&v[i+1]<=0){
      ans=max(ans,v[i]-v[i+1]+1);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
