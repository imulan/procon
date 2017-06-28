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

int V; // 頂点数 TODO:initialize
const int MAX_V = 100000; // 最大長点数 TODO:insert
vector<int> G[MAX_V]; // 隣接リスト表現
vector<int> rG[MAX_V]; // 逆辺を張ったグラフ
vector<int> vs; // 帰りがけ順の並び
bool used[MAX_V]; // 既に調べたか
int cmp[MAX_V]; //属する強連結成分トポロジカル順序

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    rep(i,G[v].size())if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v]=true;
    cmp[v]=k;
    rep(i,rG[v].size())if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    rep(v,V)if(!used[v]) dfs(v);

    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1; i>=0; --i)if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}

int main()
{
    int n;
    scanf(" %d", &n);
    V=n;

    vector<int> a(n),b(n),c(n),d(n);
    rep(i,n)
    {
        scanf(" %d %d %d %d", &a[i],  &b[i], &c[i], &d[i]);
        --a[i];
        add_edge(i,a[i]);
    }

    scc();
    ll ans = 0;
    reverse(all(vs));
    vector<int> vis(n);
    for(const auto &v:vs)
    {
        if(vis[v]) continue;

        vector<int> t;
        int now = v;
        while(!vis[now])
        {
            t.pb(now);
            vis[now]=2;
            now = a[now];
        }

        if(vis[now]==2)
        {
            int start = now;
            vector<int> loop;
            loop.pb(now);
            vis[now]=3;
            now = a[now];
            while(now!=start)
            {
                vis[now]=3;
                loop.pb(now);
                now = a[now];
            }

            int L = loop.size();
            vector<vector<ll>> dp(L,vector<ll>(2));
            dp[1][0] = (ll)b[loop[0]]*c[loop[1]];
            dp[1][1] = (ll)b[loop[0]]*d[loop[1]];

            for(int i=1; i<L-1; ++i)
            {
                rep(j,2) dp[i+1][j] = max(dp[i][j]+(ll)b[loop[i]]*c[loop[i+1]], dp[i][!j]+(ll)b[loop[i]]*d[loop[i+1]]);
            }

            ans += max(dp[L-1][0]+(ll)b[loop[L-1]]*c[loop[0]], dp[L-1][1]+(ll)b[loop[L-1]]*d[loop[0]]);
        }

        for(const auto &x:t)
        {
            if(vis[x]==2) ans += (ll)b[x]*max(c[a[x]],d[a[x]]);
            vis[x]=1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
