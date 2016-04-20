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
  int l[3],r,b,y;
  rep(i,3) cin>>l[i];
  cin >>r >>b >>y;

  sort(l,l+3);

  int ans=110101010;
  do{
    int tmp=0;
    tmp+=(2*l[0]+2*l[2])*r;
    tmp+=(2*l[0]+2*l[1])*b;
    tmp+=(2*l[1]+2*l[2])*y;
    ans=min(ans,tmp);
  } while(next_permutation(l,l+3));

  std::cout << ans << std::endl;
  return 0;
}
