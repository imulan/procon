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
  string s;
  std::cin >> s;

  int n=s.size();

  int i;
  int ans=0;
  int st=0;

  char op='*';
  s+='*';
  rep(i,n){
    if(s[i]=='+' || s[i]=='*'){//演算器号が来たら
      op=s[i];//記号を保存
      st=i+1;
    }
    else{
      if(s[i+1]=='+' || s[i+1]=='*'){
        string t=s.substr(st,i+1-st);
        int tt=atoi(t.c_str());

        if(op=='*') ans+=tt;
        else ans*=tt;

        //cout << t<<endl;
        //printf(" %d: %d\n",i,ans);
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
