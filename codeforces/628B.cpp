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

  char str[300010];
  scanf(" %s", str);
  string s=str;

  ll ans=0;
  //1桁で4で割り切れるもの
  rep(i,s.size()){
    if((s[i]-'0')%4==0) ++ans;
  }

  //下2桁が割り切れるもの
  rep(i,s.size()-1){
    int a=atoi(s.substr(i,2).c_str());
    if(a%4==0) ans+=i+1;
  }

  std::cout << ans << std::endl;
  return 0;
}
