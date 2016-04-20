#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

//(0,0)と(x,y)で囲まれる長方形で、マンハッタン距離がd以下の格子点の個数
ll m_dist(ll x, ll y, ll d){
  ll sum=d*(d+1)/2;
  if(x<d) sum-=(d-x)*(d-x+1)/2;
  if(y<d) sum-=(d-y)*(d-y+1)/2;
  return sum;
}

ll ab(ll p){
  return (p>0)?p:-p;
}

ll nrm(ll x, ll y){
  return x*x+y*y;
}

int main(int argc, char const *argv[]) {
  ll x1,y1,x2,y2,d;
  cin >>x1 >>y1 >>x2 >>y2 >>d;

  ll ans=0;
  if(x1*x2>0 && y1*y2>0){
    //1つの象限に収まっている場合
    x1=ab(x1);
    y1=ab(y1);
    x2=ab(x2);
    y2=ab(y2);

    if(nrm(x1,y1)>nrm(x2,y2)){
      swap(x1,x2);
      swap(y1,y2);
    }

    ans=m_dist(x2-x1,y2-y1,d-x1-y1);
  }

  std::cout << ans << std::endl;

  return 0;
}
