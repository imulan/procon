#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SCC{
    int V;
    vector<vector<int>> G, rG;
    vector<int> vs; // 帰りがけ順の並び
    vector<int> cmp; //属する強連結成分トポロジカル順序
    vector<bool> used;

    SCC(){}
    SCC(int n){
        V = n;
        G = vector<vector<int>>(n);
        rG = vector<vector<int>>(n);
    }

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
        used = vector<bool>(V,false);
        vs.clear();
        rep(i,V)if(!used[i]) dfs(i);

        used = vector<bool>(V,false);
        cmp = vector<int>(V);
        int num_scc = 0;
        for(int i=vs.size()-1; i>=0; --i)if(!used[vs[i]]) rdfs(vs[i],num_scc++);
        return num_scc;
    }
};

int n,m;
SCC s;

vector<vector<int>> cc;

using pi = pair<int,int>;
map<pi,int> memo;
int calc(int from, int to){
    if(memo.count({from,to})) return memo[{from,to}];
    int c = s.cmp[from];
    assert(c == s.cmp[to]);

    int sz = cc[c].size();
    map<int,int> v2id;
    rep(i,sz) v2id[cc[c][i]] = i;

    vector<vector<int>> dp(1<<sz, vector<int>(sz,0));
    int ff = v2id[from], tt = v2id[to];

    queue<pi> que;
    dp[1<<ff][ff] = 1;
    que.push({1<<ff,ff});
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        int mask = now.fi;
        int v = now.se;
        for(int nnx:s.G[cc[c][v]])if(v2id.count(nnx)){
            int nx = v2id[nnx];
//            printf("  %d _> %d\n",v,nx);
            if(!(mask>>nx&1)){
                int nmask = mask|(1<<nx);
                dp[nmask][nx] = 1;
                que.push({nmask,nx});
            }
        }
    }

    int res = 1;
    rep(mask,1<<sz)if(dp[mask][tt]) res = max(res,__builtin_popcount(mask));

//    printf(" from to %d %d :: %d\n",from,to,res);
    return memo[{from,to}] = res;
}

const int N = 100000;
int dp[N];
int dfs(int x){
    if(dp[x]>=0) return dp[x];

    int ret = 0;

    int c = s.cmp[x];
    int sz = cc[c].size();

    if(sz==1){
        ret = 1;
        for(int e:s.G[x]) ret = max(ret, dfs(e)+1);
    }
    else{
        for(int ed:cc[c]){
            int ad = calc(x,ed);
            ret = max(ret,ad);
            for(int e:s.G[ed])if(s.cmp[e]!=c){
                ret = max(ret, dfs(e)+ad);
            }
        }
    }

    return dp[x] = ret;
}

int main(){
    scanf(" %d %d", &n, &m);
    s = SCC(n);

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        s.add_edge(a,b);
    }

    int num = s.scc();
    cc = vector<vector<int>>(num);
    rep(i,n) cc[s.cmp[i]].pb(i);

//    rep(i,num){
//        for(int j:cc[i]) printf(" %d", j+1);
//        printf("\n");
//    }

    memset(dp,-1,sizeof(dp));
    int ans = 0;
    rep(i,n) ans = max(ans,dfs(i));
    printf("%d\n", ans);
    return 0;
}