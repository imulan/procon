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
  string s;
  cin >>n >>s;

  long ans=0;
  rep(i,n){//始点
    int x=0,y=0;
    j=i;
    while(j<n){
      if(s[j]=='U') ++y;
      else if(s[j]=='D') --y;
      else if(s[j]=='R') ++x;
      else if(s[j]=='L') --x;

      if(x==0&&y==0) ++ans;
      ++j;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
