#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int i;

  int n,L;
  cin >>n >>L;
  vector<int> x(n);
  x[0]=0;
  for(i=1; i<n; ++i) scanf(" %d", &x[i]);

  //x[0],...x[i]の累積和
  vector<int> xsum(n);
  xsum[0]=x[0];
  rep(i,n-1) xsum[i+1]=xsum[i]+x[i+1];

  //隣接していないところがないかチェック
  bool disjoint=true;
  rep(i,n-1){
    if(ab(x[i+1]-x[i])>=L) disjoint=false;
  }

  int ans=-1;
  if(disjoint){
    ans=0;
    for(i=n-2; i>=0; --i){
      //重心
      double g = (double)(xsum[n-1]-xsum[i])/(n-1-i)+L/2.0;

      //printf("g= %lf\n", g);

      if(x[i]<g && g<x[i]+L && x[i+1]<g && g<x[i+1]+L);
      else ++ans;
    }
  }

  printf("%d\n",ans);
  return 0;
}
