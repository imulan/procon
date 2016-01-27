#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int n;
  int x[4], y[4];

  cin >> n;
  for(int i=0; i<n; ++i) cin >> x[i] >> y[i];

  long ans=-1;

  if(n==1){}
  else if(n==2){
    if(x[0]!=x[1] && y[0]!=y[1]){
      ans = fabs(x[0]-x[1]) * fabs(y[0]-y[1]);
    }
  }
  else{
    int xx=0,yy=0;
    for(int i=1; i<n; ++i){
      xx=max(xx,(int)fabs(x[i]-x[0]));
      yy=max(yy,(int)fabs(y[i]-y[0]));
    }
    ans = (long)xx*yy;
  }
  printf("%ld\n",ans);
}
