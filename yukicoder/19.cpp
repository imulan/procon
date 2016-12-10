#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int V; // 頂点数 TODO:initialize
const int MAX_V = 100; // 最大長点数 TODO:insert
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
    rep(i,rG[v].size())if(!used[rG[v][i]]) rdfs(rG[v][i],k++);
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
    vector<int> L(n),S(n);
    rep(i,n)
    {
        scanf(" %d %d", &L[i], &S[i]);
        --S[i];
    }

    V=n;
    rep(i,n) add_edge(S[i],i);

    int SCC_size=scc();

    // connected component
    vector<int> cc[100];
    rep(i,n) cc[cmp[i]].pb(i);

    double ans=0;
    // i番目のccに到達したか
    int cc_vis[100]={};

    int vis[100]={};
    rep(now,SCC_size)
    {
        if(cc_vis[now])
        {
            rep(i,cc[now].size()) ans+=L[cc[now][i]]/2.0;
            continue;
        }

        int idx=-1;
        int min_cost=1234;
        rep(i,cc[now].size())
        {
            int t_idx=cc[now][i];
            if(min_cost > L[t_idx])
            {
                idx=t_idx;
                min_cost=L[t_idx];
            }
        }
        rep(i,cc[now].size())
        {
            if(cc[now][i]==idx) ans+=min_cost;
            else ans+=L[cc[now][i]]/2.0;
        }

        // BFS
        queue<int> que;
        que.push(cc[now][0]);
        vis[cc[now][0]]=1;
        cc_vis[now]=1;
        while(!que.empty())
        {
            int cur=que.front();
            que.pop();
            rep(i,G[cur].size())
            {
                int nx=G[cur][i];
                if(!vis[nx])
                {
                    vis[nx]=1;
                    cc_vis[cmp[nx]]=1;
                    que.push(nx);
                }
            }
        }
    }

    printf("%.1f\n", ans);
    return 0;
}
