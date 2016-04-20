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

  int n;
  cin >>n;
  vector<long> a(n);
  rep(i,n) cin>>a[i];

  long ans=0;
  rep(i,n-1) ans+=a[i+1]-a[i];
  printf("%.10lf\n",1.0*ans/(n-1));
  return 0;
}
