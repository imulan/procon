#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  string s;
  cin >>s;

  int ans=0;
  bool zero=false;
  //+で区切る
  rep(i,s.size()){
    if(s[i]=='*') continue;
    else if(s[i]=='+'){
      if(!zero) ++ans;
      zero=false;
    }
    else{
      if(s[i]=='0') zero=true;
    }
  }

  if(!zero) ++ans;

  std::cout << ans << std::endl;
  return 0;
}
