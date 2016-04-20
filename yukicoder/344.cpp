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
  long i;

  long n;
  cin >>n;

  //h_n-1とh_n-2を保存
  set<pair<int,int>> s;
  std::vector<int> h;

  //初期化
  h.pb(2);
  h.pb(2);
  s.insert(mp(2,2));

  int a=2,b=2;
  while(1){
    int c=(2*a+2*b)%1000;

    h.pb(c);
    if(s.find(mp(b,c))==s.end()){
      //printf(" in %4d %4d\n",b,c);
      s.insert(mp(b,c));
    }
    else break;

    a=b;
    b=c;
  }

  int ans;
  if(n<4) ans=h[n];
  else ans=h[4+(n-4)%600];

  if(n%2==0) ans=(ans-1+1000)%1000;

  printf("%d\n",ans);
  return 0;
}
