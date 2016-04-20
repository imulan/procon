#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  ll pw[10]={0};
  pw[0]=1;
  rep(i,9) pw[i+1]=pw[i]*26;

  ll n;
  cin >>n;

  ll tmp=0;
  ll len=0;
  while(1){
    ++len;
    tmp += pw[len];
    if(tmp>n) break;
  }

  ll minus=0;
  std::vector<ll> v;
  for(ll i=0; i<len; ++i){
    v.pb(((n-minus)/pw[i])%26);
    minus+=pw[i+1];
  }

  string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i=v.size()-1; i>=0; --i)
    printf("%c", s[v[i]]);
  printf("\n");

  return 0;
}
