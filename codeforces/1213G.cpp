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

const int N = 200002;
vector<pi> G[N];
vector<int> Q[N];

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    rep(i,n-1){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        G[w].pb({u,v});
    }

    rep(i,q){
        int w;
        scanf(" %d", &w);
        Q[w].pb(i);
    }

    UF uf(n);
    ll now = 0;
    vector<ll> ans(q);
    rep(i,N){
        for(pi e:G[i]){
            int u=e.fi, v=e.se;
            now += (ll)uf.size(u)*uf.size(v);
            uf.unite(u,v);
        }

        for(int j:Q[i]) ans[j] = now;
    }

    rep(i,q) printf("%lld%c", ans[i], " \n"[i==q-1]);
    return 0;
}
