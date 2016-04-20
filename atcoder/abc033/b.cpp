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

  std::vector<int> p(n);
  std::vector<string> s(n);
  int sum=0;
  rep(i,n){
    cin >>s[i] >>p[i];
    sum += p[i];
  }

  string ans="atcoder";
  rep(i,n){
    if(sum/2<p[i]) ans=s[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
