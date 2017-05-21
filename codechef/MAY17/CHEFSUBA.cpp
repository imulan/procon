#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

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

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,k,p;
    cin >>n >>k >>p;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    string s;
    cin >>s;

    if(k>n) k=n;

    vector<int> b(2*n);
    rep(i,n) b[i] = b[n+i] = a[i];

    int ct=0;
    rep(i,k-1) ct+=b[i];

    MaxSegTree st(n);
    rep(i,n)
    {
        ct += b[i+k-1];
        st.update(i,ct);
        ct -= b[i];
    }

    int l=0, r=n-k;
    rep(i,p)
    {
        if(s[i]=='!')
        {
            // shift
            l = (l-1+n)%n;
            r = (r-1+n)%n;
        }
        else
        {
            // maxquery
            ll ans;
            if(l<r) ans=st.query(l,r+1);
            else ans=max(st.query(0,r+1),st.query(l,n));

            printf("%lld\n", ans);
        }
    }
    return 0;
}
