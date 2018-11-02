// 最小有向全域木
// O(VE)

// (重み, u->v)
using Edge = pair<ll,pair<int,int>>;

const ll INF = LLONG_MAX/3;

// 辺集合, 頂点数, 根
ll Chu_Liu_Edmonds(const vector<Edge> es, int V, int root){
    // 頂点iに入ってくる辺(u->i)の中で、最小のコストの辺を管理 (コスト, u)
    vector<pair<ll,int>> mn(V, {INF,-1});
    for(Edge e:es){
        int u = e.se.fi, v = e.se.se;
        mn[v] = min(mn[v], {e.fi, u});
    }
    mn[root] = {0,-1};

    // 連結成分に分ける(1つの閉路に対して1つの番号を与える)
    vector<int> cmp(V);
    // この連結成分が閉路であるか
    vector<bool> cycle(V,false);
    int cc = 0;

    vector<bool> vis(V);
    rep(i,V){
        if(vis[i]) continue;

        vector<int> path;
        int now = i;

        while(now!=-1 && !vis[now]){
            vis[now] = true;
            path.pb(now);

            // 今張っている辺を逆方向にたどる
            now = mn[now].se;
        }

        if(now != -1){
            bool in_cycle = false;
            for(int j:path){
                cmp[j] = cc;
                if(j == now){
                    // 閉路の始点(これ以降のpathに入ってる頂点が閉路をなす)
                    in_cycle = true;
                    cycle[cc] = true;
                }

                if(!in_cycle) ++cc;
            }
            if(in_cycle) ++cc;
        }
        else{
            // 閉路なし
            for(int j:path) cmp[j] = cc++;
        }
    }

    if(cc == V){
        // すべての頂点が違う連結成分に分かれたので 閉路なし
        ll ans = 0;
        rep(i,V) ans += mn[i].fi;
        return ans;
    }

    // 閉路分のコスト
    ll cycle_cost = 0;
    rep(i,V){
        if(i!=root && cycle[cmp[i]]) cycle_cost += mn[i].fi;
    }

    // コストを再設定
    vector<Edge> nes;
    for(Edge e:es){
        int u = e.se.fi, v = e.se.se;
        int cu = cmp[u], cv = cmp[v];

        if(cu == cv){
            // 閉路内の辺は無視
            continue;
        }
        else if(cycle[cv]){
            // コストを再設定
            nes.pb({e.fi - mn[v].fi, {cu,cv}});
        }
        else{
            nes.pb({e.fi, {cu,cv}});
        }
    }

    return cycle_cost + Chu_Liu_Edmonds(nes, cc, cmp[root]);
};
