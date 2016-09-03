#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >>n;

  vector<long long> h(n), s(n);
  for(int i=0; i<n; ++i)
    scanf(" %lld %lld", &h[i] ,&s[i]);

  ll l=1, r=1e14;
  ll mid;
  bool end=false;

  //二分探索
  while(1){
    mid = (l+r)/2;
    //cout << mid << endl;
    //cout << l << " , " << r << endl;

    if(r-l<=1){
      end=true;
      mid=l;
    }

    bool ok=true;
    int t_ct[100000]={0};
    for(int i=0; i<n; ++i){
      ll t = mid-h[i];
      if(t<0){
        ok=false;
        break;
      }

      t=t/s[i];
      //printf(" t = %lld\n", t);
      if(t>=100000) t=99999;

      ++t_ct[t];
    }

    int lim=0;
    //判定
    for(int i=0; i<100000; ++i){
      lim+=t_ct[i];
      if(lim<=i+1){} //ok
      else{
        ok=false;
        break;
      }
    }


    if(end){
      if(!ok) mid=r;
      break;
    }

    if(ok) r=mid;
    else l=mid;
  }

  cout << mid << endl;
}
