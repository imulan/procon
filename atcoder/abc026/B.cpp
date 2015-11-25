#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
  int n, r[1000];
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) scanf(" %d", &r[i]);

  sort(r, r+n);

  double ans=0;

  int ct=1;
  for(int i=n-1; i>=0; --i){

    ans += M_PI*r[i]*r[i]*ct;
    ct=-ct;
  }

  printf("%.10lf\n", ans);
}
