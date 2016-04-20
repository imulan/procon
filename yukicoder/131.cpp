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
  long x,y,d;
  cin >>x >>y >>d;

  long left=max(d-y,(long)0);
  long right=min(d,x);
  std::cout << max(right-left+1,(long)0) << std::endl;
  return 0;
}
