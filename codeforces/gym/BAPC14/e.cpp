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

const int INF = 19191919;

struct SegTree{
    int n;
    vector<int> dat;
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat = vector<int>(2*n-1, INF);
    }

    void update(int k, int a){
        k+=n-1;
        dat[k] = a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = min(dat[2*k+1], dat[2*k+2]);
        }
    }

    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return dat[k];

        int vl = _query(a,b,2*k+1,l,(l+r)/2);
        int vr = _query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }

    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

void solve(){
    int n;
    scanf(" %d", &n);

    vector<pi> v(n);
    rep(i,n){
        int a[3];
        rep(j,3){
            scanf(" %d", &a[j]);
            --a[j];
        }

        v[a[0]] = {a[1],a[2]};
    }

    SegTree st(n);

    int ans = 0;
    rep(i,n){
        if(st.query(0,v[i].fi) > v[i].se) ++ans;
        st.update(v[i].fi, v[i].se);
    }
    printf("%d\n",ans);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
