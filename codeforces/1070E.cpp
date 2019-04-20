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
    int n;
    vector<ll> dat;

    SegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        dat = vector<ll>(2*n-1,0);
    }

    void add(int k, ll a){
        k += n-1;
        dat[k] += a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = dat[2*k+1]+dat[2*k+2];
        }
    }

    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        ll vl = _query(a,b,2*k+1,l,(l+r)/2);
        ll vr = _query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }

    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }

    int find_idx(int num){
        // printf("  num :: %d\n",num);
        int k=0,l=0,r=n;
        ll s = 0;
        while(r-l>1){
            int m = (l+r)/2;

            if(s + dat[2*k+1] < num){
                // 右
                s += dat[2*k+1];

                l = m;
                k = 2*k+2;
            }
            else{
                // 左

                r = m;
                k = 2*k+1;
            }
        }
        s += dat[k];

        if(s == num) return l;
        return -1;
    }
};


void solve(){
    int n,m;
    ll t;
    scanf(" %d %d %lld", &n, &m, &t);

    vector<int> p(n);
    rep(i,n) scanf(" %d", &p[i]);

    vector<int> up(p);
    sort(all(up));
    if(t < up.back()){
        up.pb(t);
    }
    sort(all(up));
    up.erase( unique(all(up)), up.end() );

    int U = up.size();

    vector<vector<int>> ADD(U);
    rep(i,n){
        int idx = lower_bound(all(up), p[i]) - up.begin();
        ADD[idx].pb(i);
    }

    // a : 実際の時間
    // b : あるかないか 0/1
    SegTree a(n+1),b(n+1);

    int num = -1;
    int anst = -1;
    rep(i,U){
        int tt = up[i];
        // printf(" --------- CHECK  d = %d\n",tt);

        for(int idx:ADD[i]){
            a.add(idx,tt);
            b.add(idx,1);
        }

        // x個のtask
        auto check = [&](int x){
            if(b.query(0,n) < x) return false;

            int t_idx, o_idx;
            if(x%m != 0){
                t_idx = b.find_idx(m*(x/m));
                o_idx = b.find_idx(x);
                // printf("  ( %d %d )\n",t_idx,o_idx);
            }
            else{
                t_idx = b.find_idx(m*(x/m - 1));
                o_idx = b.find_idx(x);
                // printf("  ( %d %d )\n",t_idx,o_idx);
            }

            // printf("  x %d  (%d %d)  \n",x,t_idx,o_idx);

            ll tv = a.query(0,t_idx+1);
            ll ov = a.query(t_idx+1,o_idx+1);
            ll val = tv*2 + ov;

            return val <= t;
        };

        int ok = 0, ng = n+1;
        while(ng-ok>1){
            int mid = (ok+ng)/2;
            if(check(mid)) ok = mid;
            else ng = mid;
        }

        // dbg(ok);

        if(num<ok){
            num = ok;
            anst = tt;
        }
    }

    assert(1<=anst && anst<=t);
    printf("%d %d\n", num, anst);
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T) solve();
    return 0;
}
