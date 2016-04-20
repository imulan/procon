#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int ch(char c){
  if('0'<=c && c<='9') return c-'0';
  else return c-'A'+10;
}

int main(int argc, char const *argv[]) {
  int i,j;

  int n;
  cin >>n;

  ll ans=9010101010101010101;
  for(int q=0; q<n; ++q){
    string v;
    cin >>v;

    //まずは何進法までとることが許されるかを調べる
    int m=0;
    rep(i,v.size()){
      if('0'<=v[i] && v[i]<='9'){//数字の時
        m=max(m,v[i]-'0'+1);
      }
      else{//アルファベットの時
        m=max(m,v[i]-'A'+11);
      }
    }

    //m進法を試す
    ll t=0;
    ll mul=1;
    for(j=v.size()-1; j>=0; --j){
      t+=ch(v[j])*mul;
      mul*=m;
    }
    ans=min(ans,t);

  }
  std::cout << ans << std::endl;
  return 0;
}
