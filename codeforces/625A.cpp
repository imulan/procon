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
  ll n,a,b,c;
  cin >>n >>a >>b >>c;

  ll glass=b-c;

  ll k=0;
  ll buy=min(a,b);

  if(n>=buy){
    //とりあえずコストの掛からない方で限界まで飲む
    if(a<=b-c){//プラスチックを買い続ける
      k=n/a;
    }
    else{//グラスをギリギリまで買う
      ll m=b-c;
      k=(n-b)/m;
      if(k<0) k=0;
      n -= m*k;

      while(n>=b){
        ++k;
        n-=(b-c);
      }

      if(a<=b){
        k+=n/a;
      }
      else{
        while(n>=b){
          ++k;
          n-=(b-c);
        }
      }

    }
  }

  std::cout << k << std::endl;
  return 0;
}
