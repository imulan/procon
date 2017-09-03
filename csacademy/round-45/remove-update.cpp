#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

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
    int n,Q;
    cin >>n >>Q;

    vector<int> l(Q),r(Q),x(Q);
    vector<ll> a(n+1);
    rep(i,Q)
    {
        cin >>l[i] >>r[i] >>x[i];
        --l[i];
        --r[i];
        a[l[i]] += x[i];
        a[r[i]+1] -= x[i];
    }

    rep(i,n) a[i+1] += a[i];

    MaxSegTree st(n);
    rep(i,n) st.update(i,a[i]);

    ll ans = LLONG_MAX;
    rep(i,Q)
    {
        ll t = max({st.query(0,l[i]), st.query(l[i],r[i]+1)-x[i], st.query(r[i]+1,n+1)});
        ans = min(ans,t);
    }
    cout << ans << endl;
    return 0;
}
