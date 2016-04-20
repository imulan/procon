#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  char x;
  string s;
  cin >>x >>s;

  rep(i,s.size()){
    if(s[i]!=x) cout << s[i];
  }
  cout << endl;
  return 0;
}
