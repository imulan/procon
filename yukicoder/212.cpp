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

  int a[6]={2,3,5,7,11,13};
  int b[6]={4,6,8,9,10,12};

  double e_a=0, e_b=0;
  rep(i,6){
    e_a+=a[i]/6.0;
    e_b+=b[i]/6.0;
  }

  int p,c;
  cin >>p >>c;

  printf("%.10lf\n",pow(e_a,p)*pow(e_b,c));
  return 0;
}
