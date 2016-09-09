#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef vector<int> vi;

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
};

int main()
{
    int n,m,q;
    scanf(" %d %d %d", &n, &m, &q);

    vector<pi> edge(m);
    map<pi,int> edge_id;
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        if(a>b) swap(a,b);

        edge[i]=pi(a,b);
        edge_id[edge[i]]=i;
    }

    vi destroy_id(q);
    // 最後まで残り続ける橋
    vector<bool> remain(m,true);
    rep(i,q)
    {
        int c,d;
        scanf(" %d %d", &c, &d);
        --c;
        --d;
        if(c>d) swap(c,d);

        destroy_id[i]=edge_id[pi(c,d)];
        remain[destroy_id[i]]=false;
    }

    UF final_state(n), initial_state(n);
    rep(i,m)
    {
        initial_state.unite(edge[i].fi, edge[i].se);
        if(remain[i]) final_state.unite(edge[i].fi, edge[i].se);
    }

    // -2:undefined
    vi ans(n,-2);
    for(int i=1; i<n; ++i)
    {
        // 最初から到達不可能
        if(initial_state.root(0) != initial_state.root(i)) ans[i]=0;
        // 最後まで到達可能
        if(final_state.root(0) == final_state.root(i)) ans[i]=-1;
    }

    // parallel binary search
    // クエリをl番まで処理した時にはまだ0とiはつながっていて、r番まで処理した時には繋がっていない
    vi l(n,0),r(n,q);

    rep(times,18)
    {
        vector<vi> pos(q);
        // 頂点iについて
        for(int i=1; i<n; ++i)
        {
            // undefinedのみに注目
            if(ans[i]==-2)
            {
                int mid = (l[i]+r[i])/2;
                pos[mid].pb(i);
            }
        }

        UF state(n);
        // まず最終的な状態を再現
        rep(i,m)
        {
            if(remain[i]) state.unite(edge[i].fi, edge[i].se);
        }

        // 後ろから見ていき、徐々に辺を追加していく
        for(int i=q-1; i>=0; --i)
        {
            pi e=edge[destroy_id[i]];
            state.unite(e.fi, e.se);

            if(pos[i].size()>0)
            {
                //クエリ処理
                for(const int &vnum:pos[i])
                {
                    if(state.root(0) == state.root(vnum)) l[vnum]=i;
                    else r[vnum]=i;
                }
            }
        }
    }

    for(int i=1; i<n; ++i) printf("%d\n", ans[i]==-2?r[i]:ans[i]);
    return 0;
}
