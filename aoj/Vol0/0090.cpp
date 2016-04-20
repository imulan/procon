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
  double eps=1e-6;
  while(1){
    int n;
    cin >>n;
    if(n==0) break;

    vector<double> x(n),y(n);
    rep(i,n) scanf(" %lf,%lf", &x[i], &y[i]);

    int ans=0;
    for(double X=0; X<=10; X+=0.01){
      for(double Y=0; Y<=10; Y+=0.01){
        int tmp=0;
        rep(i,n){
          if(pow(X-x[i],2)+pow(Y-y[i],2) < 1.0+eps)
            ++tmp;
        }
        ans=max(ans,tmp);
      }
    }

    std::cout << ans << std::endl;
  }
  return 0;
}
