#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int a,b;
  cin >>a >>b;
  std::cout << ab(a)+ab(a-b)+ab(b) << std::endl;
  return 0;
}
