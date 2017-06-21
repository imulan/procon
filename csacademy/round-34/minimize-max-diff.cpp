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
    int n; vector<ll> dat;
    //初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MIN);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MIN;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    MaxSegTree st(n);
    ll ans = 0;
    rep(i,n-1)
    {
        ll d = a[i+1]-a[i];
        ans = max(ans,d);
        st.update(i,d);
    }

    rep(i,k+1) ans = min(ans, st.query(i,n-1-(k-i)));

    cout << ans << endl;
    return 0;
}
