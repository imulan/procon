#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

string ch(char c){
  if(c==' ') return "0";

  int i;

  string ret="";
  if(c<='o'){
    int a=(c-'a')/3 +2;
    rep(i,(c-'a')%3+1) ret+=a+'0';
  }
  else if(c<='s'){
    rep(i,(c-'p')%4+1) ret+='7';
  }
  else if(c<='v'){
    rep(i,(c-'t')%3+1) ret+='8';
  }
  else{
    rep(i,(c-'w')%4+1) ret+='9';
  }

  return ret;
}

void solve(string s){
  int i;

  int n=s.size();
  string ans=" ";
  rep(i,n){
    string ad=ch(s[i]);
    if(ans[ans.size()-1]==ad[0]) ans+=" ";
    ans+=ad;
  }

  std::cout << ans << std::endl;
}

int main(int argc, char const *argv[]) {
  int Q;
  cin >>Q; cin.ignore();
  for(int q=1; q<=Q; ++q){
    string s;
    getline(cin,s);

    printf("Case #%d:",q);
    solve(s);
  }
  return 0;
}
