#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll a(int m, int n){
  ll ret=0;
  if(m==0) ret=n+1;
  else if(m==1) ret=n+2;
  else if(m==2) ret=2*n+3;
  else if(m==3){
    ret=1;
    for(int i=0; i<n+3; ++i) ret*=2;
    ret-=3;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int m,n;
  cin >>m >>n;
  std::cout << a(m,n) << std::endl;
  return 0;
}
