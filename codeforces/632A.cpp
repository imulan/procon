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

  int n,p;
  cin >>n >>p;
  vector<string> s(n);
  rep(i,n) cin >>s[i];

  ll nums=0;
  for(i=n-1; i>=0; --i){
    if(s[i]=="half") nums=nums*2;
    else nums=nums*2+1;
  }

  ll ans=0;
  rep(i,n){
    if(s[i]=="half"){
      ll b=nums/2;
      nums-=nums/2;
      ans+=p*b;
    }
    else{
      ll b=nums/2;
      nums-=nums/2+1;
      ans+=p*b+p/2;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
