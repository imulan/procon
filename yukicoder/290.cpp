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

  int n;
  cin >>n;
  string s;
  cin >>s;

  bool ans=false;

  //2文字連続しているところがあればそこが答え
  rep(i,n-1){
    if(s[i]==s[i+1]) ans=true;
  }

  //"01"と"10"の並びをカウント
  int zo=0,oz=0;
  rep(i,n-1){
    if(s[i]=='0' && s[i+1]=='1') ++zo;
    else if(s[i]=='1' && s[i+1]=='0') ++oz;
  }

  if(zo>=2 || oz>=2) ans=true;

  string r="NO";
  if(ans) r="YES";
  std::cout << r << std::endl;
  return 0;
}
