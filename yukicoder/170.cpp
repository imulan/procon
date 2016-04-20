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

  string s;
  cin >>s;

  vector<char> c;
  rep(i,s.size()) c.pb(s[i]);
  sort(c.begin(),c.end());

  set<string> ans;
  do {
    string t="";
    rep(i,c.size()) t+=c[i];
    ans.insert(t);
    //cout << t << endl;
  } while(next_permutation(c.begin(),c.end()));

  std::cout << ans.size()-1 << std::endl;
  return 0;
}
