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

  int g,c,p;
  string s;
  cin >>g >>c >>p >>s;

  int x=0,y=0,z=0;
  rep(i,s.size()){
    if(s[i]=='G') ++x;
    else if(s[i]=='C') ++y;
    else ++z;
  }
  //printf("%d %d %d\n",x,y,z);

  int ans=0;

  //勝ち優先
  int t=min(g,y);
  g-=t;
  y-=t;
  ans+=t*3;

  t=min(c,z);
  ans+=t*3;
  c-=t;
  z-=t;

  t=min(p,x);
  ans+=t*3;
  p-=t;
  x-=t;

  //残りで極力引き分け
  t=min(g,x);
  g-=t;
  x-=t;
  ans+=t;

  t=min(c,y);
  c-=t;
  y-=t;
  ans+=t;

  t=min(p,z);
  p-=t;
  z-=t;
  ans+=t;

  std::cout << ans << std::endl;
  return 0;
}
