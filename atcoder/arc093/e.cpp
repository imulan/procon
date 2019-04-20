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

const ll mod = 1e9+7;

using pi = pair<int,int>;
using P = pair<ll,pi>;

const int N = 2010;
ll pw[N];

int main(){
    pw[0] = 1;
    rep(i,N-1) pw[i+1] = (pw[i]*2)%mod;

    int n,m;
    ll x;
    cin >>n >>m >>x;

    if(n<=2) assert(false);

    vector<P> e(m);
    rep(i,m){
        int u,v,w;
        cin >>u >>v >>w;
        --u; --v;
        e[i] = {w,{u,v}};
    }

    sort(all(e));
    UF ALL(n);
    ll mincost = 0;
    rep(i,m){
        int u = e[i].se.fi, v = e[i].se.se;

        if(!ALL.same(u,v)){
            ALL.unite(u,v);
            mincost += e[i].fi;
        }
    }
    assert(mincost!=x);

    ll ans = 0;
    for(int i=1; i<m; ++i){
        UF uf(n);

        ll t = e[i].fi;
        uf.unite(e[i].se.fi, e[i].se.se);

        rep(j,m){
            int u = e[j].se.fi, v = e[j].se.se;
            if(!uf.same(u,v)){
                uf.unite(u,v);
                t += e[j].fi;
            }
        }

        if(uf.size(0)==n && t==x){
            (ans += 2*pw[m-1-i]) %= mod;
        }
    }

    cout << ans << endl;
    return 0;
}
