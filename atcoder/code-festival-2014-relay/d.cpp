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
  char b[128][128];
  scanf(" %d",&n);
  rep(i,n)rep(j,n) scanf(" %c", &b[i][j]);

  int x=0,y=0;
  rep(i,n){//i行目に注目
    rep(j,n){
      if(b[i][j]=='X') x+=i;
      else if(b[i][j]=='Y') y+=n-1-i;
    }
  }

  string ans="Impossible";
  if(x>y) ans="X";
  else if(x<y) ans="Y";
  std::cout << ans << std::endl;
  return 0;
}
