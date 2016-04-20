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
  string s;
  cin >>s;

  ll w=0;
  ll ans=0;
  for(int i=s.size()-1; i>=0; --i){
    if(s[i]=='w') ++w;
    else if(s[i]=='c') ans+=w*(w-1)/2;
  }

  std::cout << ans << std::endl;
  return 0;
}
