#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second


long dist2(const pair<long,long> &a, const pair<long,long> &b){
  return (a.fi-b.fi)*(a.fi-b.fi)+(a.sc-b.sc)*(a.sc-b.sc);
}

int main(int argc, char const *argv[]) {
  int i,j,k;

  int n;
  cin >>n;
  vector< pair<long,long> > p(n);
  rep(i,n) cin >>p[i].fi >>p[i].sc;

  int q=0,r=0,s=0;

  if(n<=100){
    //とりあえず全探索
    for(i=0; i<n; ++i){
      for(j=i+1; j<n; ++j){
        for(k=j+1; k<n; ++k){
          vector<long> d(3);
          d[0]=dist2(p[i],p[j]);
          d[1]=dist2(p[i],p[k]);
          d[2]=dist2(p[j],p[k]);
          sort(d.begin(),d.end());

          if(d[2]<d[0]+d[1]) ++q;
          else if(d[2]>d[0]+d[1]) ++s;
          else ++r;
        }
      }
    }
  }

  printf("%d %d %d\n",q,r,s);
  return 0;
}
