#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int n,m;
  cin >>n >>m;
  vector< vector<int> >e(n);
  vector<char> c(n,'d');
  rep(i,m){
    int a,b;
    cin >>a >>b;
    --a;
    --b;
    e[a].pb(b);
    e[b].pb(a);
  }

  bool ans=1;
  rep(i,n) sort(e[i].begin(),e[i].end());
  rep(i,n){
    if(e[i].size()==n-1) c[i]='b';
  }

  for(int i=0; i<n && ans; ++i){
    if(c[i]=='b') continue;
    if(c[i]=='d') c[i]='a';

    rep(j,n){
      if(i==j) continue;
      bool f = binary_search(e[i].begin(),e[i].end(),j);

      if(!f){
        if(c[j]=='d')c[j]=(c[i]=='a')?'c':'a';
        else if(c[j]==c[i]){
          ans=0;
          break;
        }
      }
      else if(c[j]=='a'&&c[i]=='c'||c[j]=='c'&&c[i]=='a'){
        ans=0;
        break;
      }

    }
  }

  if(ans){
    std::cout << "Yes" << std::endl;
    rep(i,n) cout << c[i];
    std::cout << std::endl;
  }
  else std::cout << "No" << std::endl;
  return 0;
}
