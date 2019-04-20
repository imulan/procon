#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

using pi = pair<int,int>;
using P = pair<pi,pi>;

const int INF = 1e9+7;

struct SegTree{
    int n; vector<int> dat;
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat = vector<int>(2*n-1,INF);
    }
    void update(int k, int a){
        k+=n-1;
        dat[k] = a;
        while(k){
            k=(k-1)/2;
            dat[k] = min(dat[2*k+1],dat[2*k+2]);
        }
    }
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return dat[k];
        int mid = (l+r)/2;
        int vl = _query(a,b,2*k+1,l,mid);
        int vr = _query(a,b,2*k+2,mid,r);
        return min(vl,vr);
    }
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<P> s(n);
    vector<int> ub;
    rep(i,n){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        s[i] = {{a,b},{c,i}};
        ub.pb(b);
    }
    sort(all(ub));
    sort(all(s));

    set<int> B,C;
    B.insert(INF);
    C.insert(INF);

    SegTree st(n);
    rep(i,n){
        int b=s[i].fi.se, c=s[i].se.fi;
        int bidx = lower_bound(all(ub), b)-ub.begin();
        st.update(bidx,c);
    }

    vector<int> ans;
    rep(i,n){
        int b=s[i].fi.se, c=s[i].se.fi, idx=s[i].se.se;
        int bidx = lower_bound(all(ub), b)-ub.begin();

        int mb = *B.begin(), mc = *C.begin();
        if(mb>b && mc>c){
            int cc = st.query(0,bidx);
            if(cc > c){
                ans.pb(idx+1);
            }
        }

        st.update(bidx,INF);
        B.insert(b);
        C.insert(c);
    }

    int z = ans.size();
    printf("%d\n",z);
    rep(i,z) printf("%d%c", ans[i], " \n"[i==z-1]);
    return 0;
}