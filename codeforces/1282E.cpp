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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

using pi = pair<int,int>;
using vi = vector<int>;

const int INF = 19191919;

struct SegTree{
    int n; vector<pi> dat;

    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pi>(2*n-1,{INF,INF});

        rep(i,n) dat[i+n-1] = {0,i};
        for(int i=n-2; i>=0; --i) dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }

    void add(int k, int a){
        k+=n-1;
        dat[k].fi += a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    // 内部的に投げられるクエリ
    pi _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {INF,INF};

        if(a<=l && r<=b) return dat[k];

        pi vl=_query(a,b,2*k+1,l,(l+r)/2);
        pi vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    // [a,b)
    pi query(int a, int b){
        return _query(a,b,0,0,n);
    }
};


void solve(){
    int n;
    scanf(" %d", &n);

    vector<vi> tri(n-2);
    vector<set<int>> idx(n);

    vector<int> ct(n);
    rep(i,n-2){
        vi t(3);
        rep(j,3){
            scanf(" %d", &t[j]);
            --t[j];

            ++ct[t[j]];
            idx[t[j]].insert(i);
        }

        tri[i] = t;
    }

    SegTree st(n);
    rep(i,n) st.add(i,ct[i]);

    UF uf(n);
    vector<vi> neighbor(n);
    vector<int> q(n-2);

    auto f = [&](int x, int y){
        uf.unite(x,y);
        neighbor[x].pb(y);
        neighbor[y].pb(x);
    };

    rep(i,n-2){
        pi p = st.query(0,n);
        assert(p.fi == 1);
        int v = p.se;
        // dbg(p);

        int tidx = *idx[v].begin();
        q[i] = tidx;

        vector<int> o;
        for(int j:tri[tidx]){
            if(j!=v) o.pb(j);

            st.add(j,-1);
            if(st.query(j,j+1).fi == 0) st.add(j,INF);
            idx[j].erase(tidx);
        }

        int sz = neighbor[v].size();
        if(sz == 0){
            f(v,o[0]);
            f(v,o[1]);
        }
        else if(sz == 1){
            if(!uf.same(v,o[0])) f(v,o[0]);
            else if(!uf.same(v,o[1])) f(v,o[1]);
        }
    }

    int now = 0, pre = -1;
    rep(i,n)if(neighbor[i].size()==1) now = i;

    vector<int> p(n);
    rep(i,n){
        p[i] = now;
        if(i==n-1) break;

        for(int j:neighbor[now]){
            if(pre != j){
                pre = now;
                now = j;
                break;
            }
        }
    }

    rep(i,n) printf("%d%c", p[i]+1, " \n"[i==n-1]);
    rep(i,n-2) printf("%d%c", q[i]+1, " \n"[i==n-3]);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
