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
using pi = pair<int,int>;

const int INF = INT_MAX/3;

struct SegTree{
    int n;
    int d;
    vector<vi> mx,mn;

    SegTree(int _n, int _k){
        n=1;
        while(n<_n) n*=2;
        d = _k;
        mx = vector<vi>(2*n-1, vi(1<<d,-INF));
        mn = vector<vi>(2*n-1, vi(1<<d, INF));
    }

    void update(int pos, const vi &b){
        rep(mask,1<<d){
            int k = pos+n-1;
            int v = 0;
            rep(i,d){
                if(mask>>i&1) v += b[i];
                else v -= b[i];
            }

            mx[k][mask] = mn[k][mask] = v;
            while(k>0){
                k=(k-1)/2;
                mx[k][mask] = max(mx[2*k+1][mask], mx[2*k+2][mask]);
                mn[k][mask] = min(mn[2*k+1][mask], mn[2*k+2][mask]);
            }
        }
    }

    pi _query(int a, int b, int k, int l, int r, int mask){
        if(r<=a || b<=l) return {-INF, INF};

        if(a<=l && r<=b) return {mx[k][mask], mn[k][mask]};

        pi vl=_query(a,b,2*k+1,l,(l+r)/2,mask);
        pi vr=_query(a,b,2*k+2,(l+r)/2,r,mask);

        return {max(vl.fi,vr.fi), min(vl.se,vr.se)};
    }
    // [a,b)
    int query(int a, int b){
        int ret = 0;
        rep(mask,1<<d){
            pi q = _query(a,b,0,0,n,mask);
            ret = max(ret, q.fi-q.se);
        }
        return ret;
    }
};

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    SegTree st(n,k);
    rep(i,n){
        vi b(k);
        rep(j,k) scanf(" %d", &b[j]);
        st.update(i,b);
    }

    int q;
    scanf(" %d", &q);
    while(q--){
        int t;
        scanf(" %d", &t);
        if(t==1){
            int pos;
            scanf(" %d", &pos);
            --pos;
            vi b(k);
            rep(i,k) scanf(" %d", &b[i]);
            st.update(pos, b);
        }
        else{
            int l,r;
            scanf(" %d %d", &l, &r);
            printf("%d\n", st.query(l-1,r));
        }
    }
    return 0;
}
