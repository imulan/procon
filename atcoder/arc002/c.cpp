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
  int n;
  string s;
  cin >>n >>s;

  string abxy="ABXY";

  int ans=10000;
  int a,b,c,d;
  rep(a,4)rep(b,4)rep(c,4)rep(d,4){
    string L="", R="";
    L+=abxy[a];
    L+=abxy[b];
    R+=abxy[c];
    R+=abxy[d];
    if(L==R) continue;

    int now=0;
    int t=0;
    while(now<n){
      if(now==n-1){
        ++t;
        break;
      }

      string tmp=s.substr(now,2);

      if(tmp==L || tmp==R) ++now;
      ++now;
      ++t;
    }

    ans=min(ans,t);
  }

  std::cout << ans << std::endl;
  return 0;
}
