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

  int n,m;
  cin >>n >>m;
  string name,kit;
  cin >>name >>kit;

  int nct[26]={0},kct[26]={0};
  rep(i,n) ++nct[name[i]-'A'];
  rep(i,m) ++kct[kit[i]-'A'];

  bool valid=true;
  int ans=0;
  rep(i,26){
    if(nct[i] && !kct[i]){
      valid=false;
      break;
    }
    int r=nct[i]/kct[i];
    if(nct[i]%kct[i]>0) ++r;
    ans=max(ans,r);
  }

  if(!valid) ans=-1;
  std::cout << ans << std::endl;
  return 0;
}
