#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = LLONG_MAX/3;

struct MinSegTree{
    int n; vector<ll> dat;
    //初期化
    MinSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,INF);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,Q,A,B;
    scanf(" %d %d %d %d", &n, &Q, &A, &B);
    --A;
    --B;

    vector<int> x(Q+1);
    x[0]=A;
    rep(i,Q)
    {
        scanf(" %d", &x[i+1]);
        --x[i+1];
    }

    ll all_add = 0;

    MinSegTree L(n),R(n);
    L.update(B, -B);
    R.update(B, B);
    rep(i,Q)
    {
        ll mm = min(L.query(0,x[i+1]+1)+x[i+1], R.query(x[i+1],n)-x[i+1]) + all_add;

        all_add += abs(x[i+1]-x[i]);

        L.update(x[i],mm-x[i]-all_add);
        R.update(x[i],mm+x[i]-all_add);
    }

    ll ans=INF;
    rep(i,n) ans=min(ans,L.query(i,i+1)+i);
    printf("%lld\n", ans+all_add);
    return 0;
}
