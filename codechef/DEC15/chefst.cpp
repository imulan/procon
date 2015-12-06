#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
  long T;
  cin >> T;
  for(int t=0; t<T; ++t){
    ll n1, n2, m;
    cin >>n1 >>n2 >>m;

    ll small=min(n1,n2), large=max(n1,n2);
    ll M = m*(m+1)/2;
    ll ans = 0;

    if(small<M) ans = max(large-small,(ll)0);
    else ans= max(n1-M, (ll)0) + max(n2-M, (ll)0);

    cout << ans << endl;
  }
}
