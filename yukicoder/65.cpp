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

  int k;
  cin >>k;

  double e[31];
  rep(i,31) e[i]=0;

  for(i=k-1; i>=0; --i){
    e[i]=1;
    for(j=1; j<=6; ++j) e[i]+=e[i+j]/6.0;
  }

  printf("%.10lf\n",e[0]);
  return 0;
}
