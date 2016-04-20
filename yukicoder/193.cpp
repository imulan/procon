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
  int n=s.size();

  int ans=-10000000;
  rep(i,n){
    string t=s.substr(i,n-i)+s.substr(0,i);
    //std::cout << t << std::endl;
    
    if(t[0]=='+' || t[0]=='-') continue;
    if(t[n-1]=='+' || t[n-1]=='-') continue;

    //数式としてokなので計算
    int tmp=0;
    int st=0;
    char op='+';
    t+='+';
    rep(j,n){
      if(t[j]=='+'||t[j]=='-'){
        op=t[j];
        st=j+1;
      }
      else if(t[j+1]=='+'||t[j+1]=='-'){
        string r=t.substr(st,j+1-st);
        //cout << r << endl;
        int ri=atoi(r.c_str());
        if(op=='+') tmp+=ri;
        else tmp-=ri;
      }
    }

    ans=max(ans,tmp);
  }

  std::cout << ans << std::endl;
  return 0;
}
