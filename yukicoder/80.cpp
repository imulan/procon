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

  int d;
  cin >>d;

  int ans=0;
  for(i=1; i*2<=d; ++i){//よこ
    int j=(d-2*i)/2;
    //printf("%d %d\n",i,j);
    ans=max(ans,i*j);
  }

  std::cout << ans << std::endl;
  return 0;
}
