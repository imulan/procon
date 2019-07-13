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

using pi = pair<int,int>;
using P = pair<pi,pi>;

const pi DUM(-1,-1);
const P NONE(DUM,DUM);

inline P append(P v, pi a){
    if(a.fi > v.fi.fi){
        v.se = v.fi;
        v.fi = a;
    }
    else if(a.fi > v.se.fi) v.se = a;
    return v;
}

inline P merge(P u, P v){
    for(pi p:{v.fi, v.se}) u = append(u,p);
    return u;
}

struct MaxSegTree{
    int n; vector<P> dat;
    // init
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<P>(2*n-1,NONE);
    }
    // at k (0-indexed)
    void add(int k, pi a){
        k += n-1;
        dat[k] = append(dat[k], a);

        while(k>0){
            k=(k-1)/2;
            dat[k]=merge(dat[2*k+1],dat[2*k+2]);
        }
    }

    P _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return NONE;

        if(a<=l && r<=b) return dat[k];

        P vl=_query(a,b,2*k+1,l,(l+r)/2);
        P vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    // [a,b)
    P query(int a, int b){
        return _query(a,b,0,0,n);
    }
};


int main(){
    int n;
    scanf(" %d", &n);

    vector<int> uh, a(n), h(n);
    rep(i,n){
        scanf(" %d %d", &a[i], &h[i]);
        uh.pb(h[i]);
    }

    sort(all(uh));
    uh.erase(unique(all(uh)), uh.end());
    int U = uh.size();

    MaxSegTree st(U);
    rep(i,n){
        int idx = lower_bound(all(uh), h[i]) - uh.begin();
        st.add(idx, {a[i],i});
    }

    int ans = 0;
    pi p(0,1);
    auto update = [&](int v, pi pidx){
        if(ans < v){
            ans = v;
            p = pidx;
        }
    };

    // one
    P top2 = st.query(0,U);
    rep(i,n){
        pi e = top2.fi;
        if(top2.fi.se == i) e = top2.se;

        if(h[i] <= e.fi) update(a[i], {i,e.se});
    }

    // two
    rep(i,n){
        int idx = upper_bound(all(uh), a[i]) - uh.begin();
        P t = st.query(0,idx);

        pi e = t.fi;
        if(t.fi.se == i) e = t.se;

        if(h[i] <= e.fi) update(a[i]+e.fi, {i,e.se});
    }

    printf("%d\n", ans);
    printf("%d %d\n", p.fi+1, p.se+1);
    return 0;
}
