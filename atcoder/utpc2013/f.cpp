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
using P = pair<int,pi>;

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

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<P> e(m);
    rep(i,m)
    {
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        e[i] = P(w,pi(u,v));
    }
    sort(all(e));

    int Q;
    scanf(" %d", &Q);
    vector<int> p(Q), q(Q);
    rep(i,Q) scanf(" %d %d", &p[i], &q[i]);

    // 各辺が使われるタイミングを並列二分探索
    vector<int> el(m,-1), er(m,Q);
    rep(_,11)
    {
        vector<vector<int>> b(Q+1);
        rep(i,m) b[(el[i]+er[i])/2].pb(i);

        UF uf(n);
        rep(i,Q)
        {
            uf.unite(p[i],q[i]);
            for(int id:b[i])
            {
                int u = e[id].se.fi, v = e[id].se.se;
                if(uf.same(u,v)) er[id] = i;
                else el[id] = i;
            }
        }
    }

    // 各辺がどのクエリで注目するかをチェック
    vector<vector<int>> merge(Q+1);
    rep(i,m) merge[er[i]].pb(i);

    // 実際にクエリを処理
    UF uf(n);
    vector<vector<int>> mst(n);
    rep(i,Q)
    {
        int a = uf.root(p[i]), b = uf.root(q[i]);

        // p[i]が属するグループのMSTを構成する辺
        vector<int> edges(mst[a]);
        // q[i]が属するグループのMSTを構成する辺
        for(int id:mst[b]) edges.pb(id);
        // その2つのグループの間に存在する辺
        for(int id:merge[i]) edges.pb(id);

        sort(all(edges));

        mst[a].clear();
        mst[b].clear();
        uf.unite(a,b);
        a = uf.root(p[i]);

        // Kruskal法で2つのグループをマージしたMSTを構成
        UF kruskal(n);
        int ans = 0;
        for(int id:edges)
        {
            int w = e[id].fi, u = e[id].se.fi, v = e[id].se.se;
            if(kruskal.same(u,v)) continue;

            kruskal.unite(u,v);
            ans += w;
            mst[a].pb(id);
        }

        // 実際に構築できていればOK
        if(uf.size(a) == kruskal.size(a)) printf("%d\n", ans);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
