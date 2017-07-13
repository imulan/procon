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

using pi = pair<int,int>;
using P = pair<pi,int>;

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
        dat[k]=min(dat[k],a);
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
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,L;
    cin >>n >>L;
    vector<P> x(n);
    rep(i,n)
    {
        int l,r,c;
        cin >>l >>r >>c;
        x[i] = P(pi(l,r),c);
    }

    sort(all(x));

    MinSegTree st(L+2);
    st.update(0,0);
    rep(i,n)
    {
        int l = x[i].fi.fi, r = x[i].fi.se, c = x[i].se;
        ll v = st.query(l,r);
        st.update(r,v+c);
    }
    cout << st.query(L,L+1) << endl;
    return 0;
}
