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

  long n;
  int m;
  cin >>n >>m;
  vector<long> a(m);
  rep(i,m) scanf(" %ld", &a[i]);

  int ans=1;
  int st=0;
  rep(i,m){
    //printf("%d ~%d  ->%ld\n",st,i, a[i]-a[st]);
    if(a[i]-a[st]>n){
      ans=max(ans,i-st);
      while(st<=i&&a[i]-a[st]>n) ++st;
      //printf("shrink %d ~%d\n",st,i);
    }
  }
  ans=max(ans,i-st);

  std::cout << ans << std::endl;
  return 0;
}
