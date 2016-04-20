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
  string a,b;
  cin >>a >>b;

  string ans;
  if(a.size()<b.size()) ans=b;
  else if(a.size()>b.size()) ans=a;
  else{
    int i;
    rep(i,a.size()){
      if(a[i]==b[i]) continue;

      if(a[i]=='4'&&b[i]=='7') ans=a;
      else if(a[i]=='7'&&b[i]=='4') ans=b;
      else{
        if(a[i]<b[i]) ans=b;
        else ans=a;
      }
      break;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
