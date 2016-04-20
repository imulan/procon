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
  int N;
  cin >>N;
  for(int cases=1; cases<=N; ++cases){
    int i,j;

    int c,n;
    cin >>c >>n;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    int x=-1,y=-1;
    rep(i,n){
      rep(j,i){
        if(p[i]+p[j]==c){
          x=j+1;
          y=i+1;
          i=j=n;
        }
      }
    }

    //output
    printf("Case #%d: %d %d\n",cases,x,y);
  }
  return 0;
}
