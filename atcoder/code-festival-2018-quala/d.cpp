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

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void add(int k, ll a){
        k+=n-1;
        (dat[k]+=a)%=mod;
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

const int N = 100010;
ll dp[N];

int main(){
    int D,F,T,n;
    cin >>D >>F >>T >>n;

    int W = F-T;

    vector<int> x;
    x.pb(0);
    rep(i,n){
        int g;
        cin >>g;
        x.pb(g);
    }
    // x.pb(D);
    n = x.size();

    vector<int> mul(n);
    rep(i,n){
        int idx = upper_bound(all(x), x[i]+W) - x.begin();
        mul[i] = idx-i-1;
    }
    // dbg(mul);

    SegTree st(n);
    dp[0] = mod_pow(2,mul[0]);
    st.add(0,dp[0]);
    for(int i=1; i<n; ++i){
        auto itr = lower_bound(all(x), x[i]-W);
        int ridx = -1;
        if(itr != x.begin()){
            --itr;
            ridx = itr - x.begin();
        }

        int lidx = lower_bound(all(x), x[i]-F) - x.begin();
        // dbg(lidx);
        // printf(" %d: [%d %d]\n",i,lidx,ridx);
        dp[i] = st.query(lidx, ridx+1);
        (dp[i] *= mod_pow(2,mul[i])) %= mod;
        st.add(i,dp[i]);
        // dbg(dp[i]);
    }

    ll ans = 0;
    rep(i,n){
        if(D-x[i]<=F) (ans += dp[i]) %= mod;
    }
    cout << ans << endl;
    return 0;
}
