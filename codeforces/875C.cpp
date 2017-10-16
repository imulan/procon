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

using vi = vector<int>;

int V; // 頂点数 TODO:initialize
const int MAX_V = 200000; // 最大長点数 TODO:insert
vector<int> G[MAX_V]; // 隣接リスト表現
vector<int> rG[MAX_V]; // 逆辺を張ったグラフ
vector<int> vs; // 帰りがけ順の並び
bool used[MAX_V]; // 既に調べたか
int cmp[MAX_V]; //属する強連結成分トポロジカル順序

void add_edge(int from, int to){
    // printf(" ADD: %d -> %d\n", from,to);
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

void solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    V = 2*m;

    vector<vi> w(n);
    rep(i,n)
    {
        int L;
        scanf(" %d", &L);
        w[i] = vi(L);
        rep(j,L)
        {
            scanf(" %d", &w[i][j]);
            --w[i][j];
        }
    }

    // 0~m-1: small
    // m~2m-1:large
    rep(i,n-1)
    {
        // dbg(i);
        int L = min(w[i].size(), w[i+1].size());

        int idx = 0;
        while(idx<L && w[i][idx]==w[i+1][idx]) ++idx;

        if(idx==L)
        {
            if(w[i].size()>w[i+1].size())
            {
                printf("No\n");
                return;
            }
        }
        else
        {
            if(w[i][idx]>w[i+1][idx])
            {
                // ~w[i+1][idx] v ~w[i][idx]
                add_edge(w[i+1][idx], w[i][idx]+m);
                add_edge(w[i][idx], w[i+1][idx]+m);

                // w[i+1][idx] v ~w[i][idx]
                add_edge(w[i+1][idx]+m, w[i][idx]+m);
                add_edge(w[i][idx], w[i+1][idx]);

                // w[i+1][idx] v w[i][idx]
                add_edge(w[i+1][idx]+m, w[i][idx]);
                add_edge(w[i][idx]+m, w[i+1][idx]);
            }
            else
            {
                // ~w[i][idx] v w[i+1][idx]
                add_edge(w[i][idx], w[i+1][idx]);
                add_edge(w[i+1][idx]+m, w[i][idx]+m);
            }
        }
    }

    scc();

    rep(i,m)
    {
        if(cmp[i] == cmp[m+i])
        {
            printf("No\n");
            return;
        }
    }

    vector<int> ans;
    rep(i,m)
    {
        if(cmp[i]<cmp[m+i]) ans.pb(i+1);
    }

    int A = ans.size();
    printf("Yes\n%d\n",A);
    rep(i,A) printf("%d%c", ans[i], (i==A-1)?'\n':' ');
}

int main()
{
    solve();
    return 0;
}
