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
    int n; vector<int> dat;
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]|dat[2*k+2];
        }
    }
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl|vr;
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    SegTree st(n);
    rep(i,n) st.update(i,a[i]);

    vector<pair<int,int>> q(n);
    rep(i,n) q[i] = {a[i],i};
    sort(all(q));
    reverse(all(q));

    set<int> s;
    s.insert(-1);
    s.insert(n);

    ll ans = 0;
    rep(i,n)
    {
        int val = q[i].fi;
        int idx = q[i].se;

        int L,R;
        auto itr = s.lower_bound(idx);
        R = *itr;
        --itr;
        L = *itr;

        int l,r;
        int x,y;

        // 左側
        l = L;
        r = idx;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(val < (val|st.query(m,idx+1))) l=m;
            else r=m;
        }
        x = r;

        // 右側
        l = idx;
        r = R;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(val < (val|st.query(idx,m+1))) r=m;
            else l=m;
        }
        y = l;

        ll U = (ll)(idx-L)*(R-idx);
        ll d = (ll)(idx-x+1)*(y-idx+1);
        ans += U-d;
        s.insert(idx);
    }
    printf("%lld\n", ans);
    return 0;
}
