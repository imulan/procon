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
  int n;
  cin >>n;
  std::vector<long> a(n);
  rep(i,n) cin >>a[i];
  sort(a.begin(), a.end());

  ll ans=0;
  set<long> use;
  for(int i=a.size()-1; i>=0; --i){
    bool end=false;
    long t=a[i];
    while(1){
      if(use.find(t)==use.end()){
        end=true;
        use.insert(t);
        ans+=t;
        break;
      }
      else --t;
      if(t==0) break;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
