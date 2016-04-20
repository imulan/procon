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

  int n,b;
  cin >>n >>b;

  double x=0, y=0;
  rep(i,n){
    double a;
    cin >>a;

    x+=a*pow(b,a-1.0);

    if(a==-1.0) y+=log(b);
    else y+=pow(b,a+1.0)/(a+1.0);
  }

  printf("%.10lf\n%.10lf\n",x,y);
  return 0;
}
