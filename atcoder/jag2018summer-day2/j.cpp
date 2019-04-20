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
using P = pair<pi,int>;
const int INF = 19191919;

struct LazySegTree{
    int n;
    vector<int> mx,mn,rt,lazy;
    vector<int> sa,sz;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;

        mx = vector<int>(2*n-1,0);
        mn = vector<int>(2*n-1,0);
        rt = vector<int>(2*n-1,0);
        lazy = vector<int>(2*n-1,0);
        sa = vector<int>(2*n-1,0);
        sz = vector<int>(2*n-1,0);
    }

    void show(){
        printf("\n    mx mn rt sa sz lz\n");
        rep(i,2*n-1){
            printf("%2d: %2d %2d %2d %2d %2d (%d)\n",i, mx[i], mn[i], rt[i], sa[i], sz[i], lazy[i]);
        }
    }

    void setLazy(int k){
        lazy[k] = !lazy[k];

        mx[k] *= -1;
        mn[k] *= -1;
        swap(mx[k],mn[k]);
        rt[k] *= -1;
        sa[k] = sz[k] - sa[k];
    }

    void push(int k, int l, int r){
        if(lazy[k]){
            setLazy(2*k+1);
            setLazy(2*k+2);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        mx[k] = max(mx[2*k+1], rt[2*k+1]+mx[2*k+2]);
        mn[k] = min(mn[2*k+1], rt[2*k+1]+mn[2*k+2]);
        rt[k] = rt[2*k+1] + rt[2*k+2];
        sa[k] = sa[2*k+1] + sa[2*k+2];
        sz[k] = sz[2*k+1] + sz[2*k+2];
    }

    void init(const string &s){
        int S = s.size();
        rep(i,S){
            int idx = i+n-1;
            if(s[i]=='A'){
                mx[idx] = 1;
                mn[idx] = 1;
                rt[idx] = 1;
                sa[idx] = 1;
            }
            else{
                mx[idx] = -1;
                mn[idx] = -1;
                rt[idx] = -1;
                sa[idx] = 0;
            }
            sz[idx] = 1;
        }

        for(int i=n-2; i>=0; --i) fix(i,-1,-1);
    }

    P merge(P x, P y){
        return {{min(x.fi.fi, x.fi.se+y.fi.fi), x.fi.se+y.fi.se}, x.se+y.se};
    }

    //内部的に投げられるクエリ
    void _flip(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k);
            return;
        }

        push(k,l,r);

        _flip(a,b,2*k+1,l,(l+r)/2);
        _flip(a,b,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)
    void flip(int a, int b){
        return _flip(a,b,0,0,n);
    }

    //内部的に投げられるクエリ
    P _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {{INF,INF}, 0};
        if(a<=l && r<=b) return {{mn[k],rt[k]}, sa[k]};

        push(k,l,r);

        P vl=_query(a,b,2*k+1,l,(l+r)/2);
        P vr=_query(a,b,2*k+2,(l+r)/2,r);

        return merge(vl,vr);
    }
    //[a,b)
    int query(int a, int b){
        P res =  _query(a,b,0,0,n);
        return res.se - res.fi.fi - 1;
    }
};


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    string s;
    cin >>n >>s;

    s = 'B'+s+'A';
    n += 2;

    LazySegTree st(n);
    st.init(s);
    // st.show();
    int Q;
    cin >>Q;
    while(Q--){
        int l,r;
        cin >>l >>r;
        ++l;
        ++r;

        st.flip(l,r+1);
        cout << st.query(0,n) << "\n";
        // st.show();
    }
    return 0;
}
