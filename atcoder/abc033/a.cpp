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
  int i;
  string n;
  cin >>n;

  set<int> s;
  rep(i,4) s.insert(n[i]-'0');

  string ans="DIFFERENT";
  if(s.size()==1) ans="SAME";

  std::cout << ans << std::endl;
  return 0;
}
