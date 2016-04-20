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

  int n;
  cin >>n;
  int ct=0;
  rep(i,n-1){
    int s,t;
    scanf(" %d %d",&s,&t);
    if(s==1 || t==1) ++ct;
  }

  string ans="A";
  if(ct>1){
    if(n%2==1) ans="B";
  }
  std::cout << ans << std::endl;
  return 0;
}
