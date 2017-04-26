#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
const int INF=123456789;
const pi PINF(INF,INF);

struct MinSegTree{
    int n; vector<pi> dat;
    //初期化
    MinSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pi>(2*n-1,PINF);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, pi a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    pi _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return PINF;

        if(a<=l && r<=b) return dat[k];

        pi vl=_query(a,b,2*k+1,l,(l+r)/2);
        pi vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    pi query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

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
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);

    vector<int> a(n);
    MinSegTree st(n);
    SumSegTree alive(n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        st.update(i,pi(-a[i],i));
        alive.update(i,1);
    }

    vector<int> ans(n,-1);
    rep(i,n)
    {
        int l=0,r=n;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(alive.query(0,m+1) <= k+1) l=m;
            else r=m;
        }

        pi v = st.query(0,min(n,l+1));
        int idx = v.se;

        ans[i] = -v.fi;
        st.update(idx,PINF);
        alive.update(idx,0);

        k -= alive.query(0,idx);
    }

    // output
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
