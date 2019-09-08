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

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    map<int,vector<pi>> edge;
    rep(i,m){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        edge[w].pb({u,v});
    }

    int ans = 0;
    UF uf(n);
    for(const auto &group:edge){
        vector<pi> e = group.se;
        int E = e.size();
        vector<bool> useful(E);
        rep(i,E){
            int u = e[i].fi, v = e[i].se;
            useful[i] = !uf.same(u,v);
        }

        rep(i,E){
            int u = e[i].fi, v = e[i].se;
            bool res = uf.unite(u,v);
            if(useful[i] && !res) ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}
