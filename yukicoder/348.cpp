#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pii;

int main(int argc, char const *argv[]) {
  int i,j;

  int n,m;
  cin >>n >>m;
  std::vector<string> s;
  rep(i,n) cin >>s[i];

  int g[1000][1000]={0};
  int now=1;

  rep(i,n){
    rep(j,m){
      if(s[i][j]=='x' && g[i][j]==0){
        //BFS
        pii p
      }
    }
  }


  return 0;
}
