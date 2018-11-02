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

// (重み, u->v)
using Edge = pair<double,pair<int,int>>;

const double INF = 19191919;

// 辺集合, 頂点数, 根
double Chu_Liu_Edmonds(const vector<Edge> es, int V, int root){
    // 頂点iに入ってくる辺(u->i)の中で、最小のコストの辺を管理 (コスト, u)
    vector<pair<double,int>> mn(V, {INF,-1});
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
        double ans = 0;
        rep(i,V) ans += mn[i].fi;
        return ans;
    }

    // 閉路分のコスト
    double cycle_cost = 0;
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

double size(const vector<double> &v){
    int n = v.size();
    double ret = 0;
    rep(i,n) ret += v[i]*v[i];
    return ret;
}

vector<double> getv(const vector<double> &v, const vector<double> &u, double r){
    int n = v.size();
    vector<double> ret(n);
    rep(i,n) ret[i] = v[i]+u[i]*r;
    return ret;
}

const double LIM = 100;
double calc(const vector<double> &v, const vector<double> &u){
    int n = v.size();

    double l=-LIM, r=LIM;
    rep(loop,60){
        double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
        if(size(getv(v,u,m1)) < size(getv(v,u,m2))) r = m2;
        else l = m1;
    }

    return size(getv(v,u,r));
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<vector<double>> v(m);
    rep(i,m){
        vector<double> tmp(n);
        rep(j,n) cin >>tmp[j];
        v[i] = tmp;
    }

    vector<Edge> Es;
    rep(i,m)rep(j,m)if(i!=j){
        Es.pb({calc(v[j],v[i]),{i,j}});
        // printf(" %d %d  -> %f\n",i,j,calc(v[j],v[i]));
    }

    double ans = INF;
    rep(i,m){
        double res = Chu_Liu_Edmonds(Es,m,i);
        ans = min(ans, size(v[i])+res);
        // printf("  %d::  %f\n",i,res);
    }
    printf("%.10f\n", ans);
    return 0;
}
