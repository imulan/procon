#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  int n,m;
  cin >>n >>m;
  int sc[9][9]={0};
  rep(i,m){
    int a,b,c;
    cin >>a >>b >>c;
    sc[a][b]=c;
  }

  std::vector<int> v(n);
  rep(i,n) v[i]=i;

  //全探索
  int ans=0;
  do {
    int t=0;
    rep(i,n){
      rep(j,i){
        t+=sc[v[j]][v[i]];
      }
    }
    ans=max(t,ans);
  } while(next_permutation(v.begin(),v.end()));

  std::cout << ans << std::endl;
  return 0;
}
