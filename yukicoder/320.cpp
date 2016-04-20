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

  ll a[81]={0};
  a[1]=a[2]=1;
  for(i=3; i<=80; ++i) a[i]=a[i-1]+a[i-2];
  
  int n;
  ll m;
  cin >>n >>m;

  //本来の値とどれくらい離れているか
  ll d=a[n]-m;

  int ans=0;
  ll now=n-2;
  while(now>0 || d>0){
    if(d-a[now]>=0){
      d-=a[now];
      ++ans;
    }
    --now;
  }

  if(d!=0) ans=-1;

  std::cout << ans << std::endl;
  return 0;
}
