#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using vi = vector<int>;

struct SegTree{
    int n; vector<int> dat;
    // 初期化
    SegTree(){}
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }

    void add(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    // 内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    // [a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const ll mod = 998244353;
const int N = 200002;
ll p2[N];

int main(){
    p2[0] = 1;
    for(int i=1; i<N; ++i) p2[i] = (p2[i-1]*2)%mod;

    int n;
    cin >>n;

    vi x(n),y(n);
    vi ux,uy;
    rep(i,n){
        cin >>x[i] >>y[i];
        ux.pb(x[i]);
        uy.pb(y[i]);
    }

    sort(all(ux));
    sort(all(uy));

    vector<int> h(n);
    rep(i,n){
        int idx = lower_bound(all(ux), x[i]) - ux.begin();
        h[idx] = lower_bound(all(uy), y[i]) - uy.begin();
    }

    // 0:lower, 1:upper
    vector<vi> L(n,vi(2)), R(n,vi(2));
    SegTree t;

    t = SegTree(n);
    rep(i,n){
        int Y = h[i];
        L[i][0] = t.query(0,Y);
        L[i][1] = t.query(Y+1,n);
        t.add(Y, 1);
    }
    t = SegTree(n);
    for(int i=n-1; i>=0; --i){
        int Y = h[i];
        R[i][0] = t.query(0,Y);
        R[i][1] = t.query(Y+1,n);
        t.add(Y, 1);
    }

    ll ans = 0;
    rep(i,n){
        // not include p[i]
        rep(lm,1<<2)rep(rm,1<<2){
            bool valid = false;
            rep(j,2){
                if((lm>>j&1) && (rm>>(!j)&1)) valid = true;
            }
            if(!valid) continue;

            ll add = 1;
            rep(j,2){
                if(lm>>j&1) (add *= (p2[L[i][j]]-1+mod)) %= mod;
                if(rm>>j&1) (add *= (p2[R[i][j]]-1+mod)) %= mod;
            }
            (ans += add) %= mod;
        }

        // include p[i]
        (ans += p2[n-1]) %= mod;
    }
    cout << ans << "\n";
    return 0;
}
