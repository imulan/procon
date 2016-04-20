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
  int Q;
  cin >>Q;
  for(int q=0;q<Q;++q){
    int i;

    string s,t;
    cin >>s >>t;

    //文字列tの含まれる文字か
    int use[26]={0};
    rep(i,t.size()) use[t[i]-'a']=1;

    string nx="";
    //tに含まれていない文字は除外
    rep(i,s.size()){
      if(use[s[i]-'a']) nx+=s[i];
    }
    //std::cout << nx << std::endl;

    bool valid=false;
    if(nx.size()>=t.size()){
      for(i=0; i<=nx.size()-t.size(); ++i){
        if(nx.substr(i,t.size())==t){
          valid=true;
          break;
        }
      }
    }

    string ans="NO";
    if(valid) ans="YES";
    std::cout << ans << std::endl;
  }
  return 0;
}
