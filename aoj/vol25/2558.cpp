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

using graph = vector<vector<int>>;
using pi = pair<int,int>;

const int INF = 191919;

int ans = INF;
int n,m,k;

graph G;
void dfs(int num){
    int v = -1;
    int sz = 0;
    rep(i,n)if(sz < G[i].size()){
        v = i;
        sz = G[i].size();
    }

    if(v==-1){
        ans = min(ans,num);
        return;
    }
    if(num>=k) return;

    set<pi> E;
    // use v
    for(int e:G[v]) E.insert({e,v});
    for(const auto &p:E){
        int a = p.fi, b = p.se;

        if(G[a].size()==0) continue;
        int idx = 0;
        while(G[a][idx]!=b) ++idx;
        swap(G[a][idx], G[a].back());
        G[a].pop_back();

        // idx = 0;
        // while(G[b][idx]!=a) ++idx;
        // swap(G[b][idx], G[b].back());
        // G[b].pop_back();
    }
    G[v].clear();

    dfs(num+1);
    for(const auto &p:E){
        int a = p.fi, b = p.se;
        G[a].pb(b);
        G[b].pb(a);
    }

    // not use v
    if(num+sz<=k && num+sz<ans){
        E.clear();
        vector<bool> cl(n);
        for(int e:G[v]){
            cl[e] = true;
            for(int nx:G[e]) E.insert({ min(nx,e), max(nx,e) });
        }
        cl[v] = true;
        for(const auto &p:E){
            int a = p.fi, b = p.se;
            if(!cl[a]){
                int idx = 0;
                while(G[a][idx]!=b) ++idx;
                swap(G[a][idx], G[a].back());
                G[a].pop_back();
            }

            if(!cl[b]){
                int idx = 0;
                while(G[b][idx]!=a) ++idx;
                swap(G[b][idx], G[b].back());
                G[b].pop_back();
            }
        }
        for(int e:G[v]) G[e].clear();
        G[v].clear();

        dfs(num+sz);
        for(const auto &p:E){
            int a = p.fi, b = p.se;
            G[a].pb(b);
            G[b].pb(a);
        }
    }
}

int main(){
    scanf(" %d %d %d", &n, &m, &k);

    G = graph(n);
    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0);
    if(ans == INF) puts("Impossible");
    else printf("%d\n",ans);
    return 0;
}
