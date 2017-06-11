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
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        add_edge(a-1,b-1);
    }

    V = n;
    scc();

    int ans = 0;
    reverse(all(vs));
    vector<bool> vis(n,false);
    for(const auto &x:vs)
    {
        if(vis[x]) continue;

        ++ans;
        vis[x]=true;
        queue<int> que;
        que.push(x);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for(const auto &nx:G[v])
            {
                if(!vis[nx])
                {
                    vis[nx]=true;
                    que.push(nx);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
