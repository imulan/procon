#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

/******************************
 MaxSegTree.cpp  START
******************************/

/******************************
 区間の最大値を返すSegmentTree
******************************/

struct MaxSegTree{
  long n; vector<ll> dat;
  //初期化
  MaxSegTree(long _n){
    n=1;
    while(n<_n) n*=2;
    dat=vector<ll>(2*n-1,LLONG_MIN);
  }
  //k番目(0-indexed)の値をaに変更
  void update(long k, ll a){
    k+=n-1;
    dat[k]=a;
    //更新
    while(k>0){
      k=(k-1)/2;
      dat[k]=max(dat[2*k+1],dat[2*k+2]);
    }
  }
  //内部的に投げられるクエリ
  ll _query(long a, long b, long k, long l, long r){
    if(r<=a || b<=l) return LLONG_MIN;

    if(a<=l && r<=b) return dat[k];
    else{
      ll vl=_query(a,b,2*k+1,l,(l+r)/2);
      ll vr=_query(a,b,2*k+2,(l+r)/2,r);
      return max(vl,vr);
    }
  }
  //[a,b)の最大値を求める
  ll query(long a, long b){
    return _query(a,b,0,0,n);
  }
};

/******************************
 MaxSegTree.cpp  END
******************************/

const double PI=acos(-1.0);

int main(int argc, char const *argv[]) {
  long i;

  long n;
  cin >>n;

  vector<long> r(n),h(n);

  vector<ll> v(n);
  vector<ll> sv(n);

  rep(i,n){
    scanf(" %ld %ld", &r[i],&h[i]);
    sv[i]=v[i]=(ll)r[i]*r[i]*h[i];
  }

  sort(sv.begin(),sv.end());
  //重複要素の削除
  sv.erase(unique(sv.begin(),sv.end()),sv.end());

  long S=sv.size();

  vector<ll> pos(n);
  rep(i,n){
    pos[i]=lower_bound(sv.begin(),sv.end(),v[i])-sv.begin();
  }

  MaxSegTree sgt(S);

  rep(i,n){
    ll b=pos[i];
    ll x=max(0LL,sgt.query(0,b));
    sgt.update(b, sv[b]+x);
  }

  printf("%.20lf\n",sgt.query(0,S)*PI);
  return 0;
}
