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

  int d;
  cin >>d;

  string x="";
  rep(i,d) x+="x";

  string a,b;
  cin >>a >>b;
  //末尾に平日を足しておく
  string s=x+a+b+x;

  int ans=0;
  for(i=0; i<s.size()-d+1; ++i){//有給を始める日
    if(s[i]=='o') continue;

    string t=s;
    int now=0;
    int t_index=i;
    while(t[t_index]=='x' && now<d){
      t[t_index++]='o';
      ++now;
    }

    //cout << t << endl;

    int st=0;
    rep(j,t.size()){
      if(t[j]=='x'){
        ans=max(ans,j-st);
        st=j+1;
      }
    }
    ans=max(ans,(int)t.size()-st);

  }

  std::cout << ans << std::endl;
  return 0;
}
