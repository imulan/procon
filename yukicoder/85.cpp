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
  int n,m,c;
  cin >>n >>m >>c;

  bool v=true;
  if(n*m>2){
    if(n==1 || m==1) v=false;
    else if(n%2==1 && m%2==1) v=false;
  }

  string ans="NO";
  if(v) ans="YES";
  std::cout << ans << std::endl;
  return 0;
}
