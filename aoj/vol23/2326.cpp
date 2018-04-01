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

struct SegTree{
    int n; vector<ll> dat;
    ll mod;
    //初期化
    SegTree(int _n, ll _mod){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);

        mod = _mod;
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=(dat[2*k+1]+dat[2*k+2])%mod;
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return (vl+vr)%mod;
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

using P = pair<string, int>;

int main(){
    int a,b,p;
    while(cin >>a >>b >>p,a){
        int n = b-a+1;
        SegTree st(n+1,p);

        vector<P> v;
        for(int i=1; i<=b-a+1; ++i){
            int val = a+i-1;
            v.pb({to_string(val), i});
        }
        sort(all(v));

        st.update(0,1);
        rep(i,v.size()){
            int idx = v[i].se;
            st.update(idx, st.query(0,idx));
        }

        cout << st.query(1,n+1) << endl;
    }
    return 0;
}
