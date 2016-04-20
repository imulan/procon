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
  vector<int> a(n);
  rep(i,n) cin >>a[i];

  int ans=-1;
  for(int s=1; s<=1000; ++s){
    bool valid=true;
    rep(j,n){
      if((a[j]*s)%100 != 0) valid=false;
    }
    if(valid){
      ans=s;
      break;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
