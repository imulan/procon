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

using P = pair<ll,ll>;

inline bool cmp(const P& a,const P& b){
  return a.fi*b.se < a.se*b.fi;
}

ll c,d;

struct SegTree{
    int n;
    vector<vector<P>> dat;
    vector<vector<ll>> sa,sb;

    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat = vector<vector<P>>(2*n-1);
        sa = vector<vector<ll>>(2*n-1);
        sb = vector<vector<ll>>(2*n-1);
    }

    vector<P> merge(const vector<P> &a, const vector<P> &b){
        int A = a.size(), B = b.size();
        vector<P> ret(A+B);

        int ridx = 0;
        int j=0;
        rep(i,A){
            while(j<B && cmp(b[j],a[i])){
                ret[ridx] = b[j];
                ++j;
                ++ridx;
            }
            ret[ridx] = a[i];
            ++ridx;
        }
        while(j<B){
            ret[ridx] = b[j];
            ++j;
            ++ridx;
        }
        return ret;
    }

    void init(const vector<ll> &a, const vector<ll> &b){
        int sz = a.size();
        rep(i,sz){
            if(a[i]==0 && b[i]==0) continue;

            int idx = i+n-1;
            dat[idx].resize(1);
            dat[idx][0] = P(a[i],b[i]);
        }

        // merge
        for(int i=n-2; i>=0; --i){
            dat[i] = merge(dat[2*i+1], dat[2*i+2]);
        }

        rep(i,2*n-1){
            ll ta = 0, tb = 0;
            int D = dat[i].size();
            sa[i].resize(D+1);
            sb[i].resize(D+1);

            rep(j,D){
                sa[i][j] = ta;
                sb[i][j] = tb;

                ta += dat[i][j].fi;
                tb += dat[i][j].se;
            }

            sa[i][D] = ta;
            sb[i][D] = tb;

            // dbg(dat[i]);
            // dbg(sa[i]);
            // dbg(sb[i]);
        }
    }

    //内部的に投げられるクエリ
    P _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return P(0,0);

        if(a<=l && r<=b){
            int idx = upper_bound(all(dat[k]), P(d,c), cmp) - dat[k].begin();

            ll resa = sa[k].back() - sa[k][idx];
            ll resb = sb[k].back() - sb[k][idx];

            // dbg(idx);
            // dbg(dat[k]);
            // dbg(sa[k]);
            // dbg(sb[k]);
            // printf(" RET : [%d, %d),  %lld, %lld\n", l,r,resa,resb);
            return P(resa, resb);
        }

        P vl=_query(a,b,2*k+1,l,(l+r)/2);
        P vr=_query(a,b,2*k+2,(l+r)/2,r);
        return P(vl.fi+vr.fi, vl.se+vr.se);
    }
    //[a,b)
    P query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<ll> a(n),b(n);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,n) scanf(" %lld", &b[i]);

    SegTree st(n);
    st.init(a,b);

    int q;
    scanf(" %d", &q);
    while(q--){
        int l,r;
        scanf(" %d %d %lld %lld", &l, &r, &c, &d);
        --l;

        P res = st.query(l,r);
        printf("%lld\n", res.fi*c - res.se*d);
        fflush(stdout);
    }
    return 0;
}
