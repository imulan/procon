#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SumSegTree{
    int n; vector<ll> dat;
    //初期化
    SumSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

using pi = pair<int,int>;

int main()
{
    int n;
    scanf(" %d", &n);

    vector<pi> p(n);
    rep(i,n)
    {
        int b;
        scanf(" %d", &b);
        p[i] = pi(b,i);
    }
    sort(all(p));
    reverse(all(p));

    ll ans = 0;
    SumSegTree st(n);
    rep(i,n)
    {
        int idx = p[i].se;
        ans += min(st.query(0,idx),st.query(idx,n));
        st.update(idx,1);
    }

    printf("%lld\n", ans);
    return 0;
}
