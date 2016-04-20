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
  int a1,a2,b1,b2,c;
  cin >>a1 >>a2 >>b1 >>b2 >>c;

  set<int> s;
  if(c==a1 || c==a2){
    s.insert(b1);
    s.insert(b2);
  }
  if(c==b1 || c==b2){
    s.insert(a1);
    s.insert(a2);
  }

  std::cout << s.size() << std::endl;
  each(it,s) std::cout << *it << std::endl;
  return 0;
}
