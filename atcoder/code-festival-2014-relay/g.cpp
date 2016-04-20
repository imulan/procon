#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int N=20100;

int main(int argc, char const *argv[]) {
  int i;

  int n,m;
  cin >>n >>m;
  vector<int> a(n);
  rep(i,n) cin >>a[i];

  bool ok[N];
  fill(ok,ok+N,false);
  ok[0]=true;

  rep(i,n){
    for(int j=N-1-a[i]; j>=0; --j){
      if(ok[j]) ok[j+a[i]]=true;
    }
  }

  int ans=-1;
  for(i=m; i<N; ++i){
    if(ok[i]){
      ans=i;
      break;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
