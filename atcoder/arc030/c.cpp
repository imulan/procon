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
const int MAX_V = 300; // 最大長点数 TODO:insert
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

const string INF="~";
string dp[300][301];

int main()
{
    // input
    int n,m,K;
    scanf(" %d %d %d", &n, &m, &K);

    V = n;

    vector<char> c(n);
    rep(i,n) scanf(" %c", &c[i]);

    vector<int> a(m),b(m);
    rep(i,m)
    {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];

        add_edge(a[i],b[i]);
    }

    int SCC = scc();

    // SCC i と SCC jはつながっているか
    int connected[300][300]={};
    rep(i,m)
    {
        int ca=cmp[a[i]], cb=cmp[b[i]];
        assert(ca<=cb);
        connected[ca][cb]=1;
    }

    // i番目のSCCに含まれる頂点集合
    vector<vector<int>> components(SCC);
    rep(i,n) components[cmp[i]].pb(i);

    // solve
    fill(dp[0],dp[300],INF);

    string s="";
    rep(i,components[0].size())
    {
        int v_num = components[0][i];
        s += c[v_num];
    }
    sort(all(s));

    dp[0][0]="";
    string tmp="";
    rep(i,s.size())
    {
        tmp += s[i];
        dp[0][i+1] = tmp;
    }

    for(int i=1; i<SCC; ++i)
    {
        rep(j,i)if(connected[j][i])
        {
            rep(k,301) dp[i][k] = min(dp[i][k], dp[j][k]);
        }

        s="";
        rep(j,components[i].size())
        {
            int v_num = components[i][j];
            s += c[v_num];
        }
        sort(all(s));

        tmp="";
        rep(j,s.size())
        {
            tmp += s[j];
            dp[i][j+1] = min(dp[i][j+1], tmp);

            rep(k,i)if(connected[k][i])
            {
                rep(l,301)
                {
                    if(dp[k][l]==INF) continue;

                    dp[i][l+j+1] = min(dp[i][l+j+1], dp[k][l]+tmp);
                }
            }
        }
    }

    // output
    string ans = INF;
    rep(i,SCC) ans = min(ans,dp[i][K]);
    if(ans == INF) ans="-1";
    cout << ans << endl;
    return 0;
}
