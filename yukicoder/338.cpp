#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long A,B;
  cin >>A >>B;

  int ans=-1;
  for(int k=1; k<=1000; ++k){
    for(int a=0; a<=k; ++a){
      int b=k-a;

      double p=100.0*a/k;
      double q=100.0*b/k;

      long pp=lround(p);
      long qq=lround(q);

      if(pp==A && qq==B){
        //printf("pp:%ld qq:%ld\n", pp, qq);
        ans=k;
        break;
      }
    }
    if(ans>0) break;
  }

  std::cout << ans << std::endl;
  return 0;
}
