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
  vector<string> s(n);
  rep(i,n) cin >>s[i];

  long ans=0;
  //横
  rep(i,n){
    long ct=0;
    rep(j,n){
      if(s[i][j]=='C') ++ct;
    }
    ans+=ct*(ct-1)/2;
  }

  //縦
  rep(i,n){
    long ct=0;
    rep(j,n){
      if(s[j][i]=='C') ++ct;
    }
    ans+=ct*(ct-1)/2;
  }

  std::cout << ans << std::endl;
  return 0;
}
