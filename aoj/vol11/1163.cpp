#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int MAX_V = 1000;
int V; //頂点数
vector<int> G[MAX_V]; //グラフ
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // dfsで既に調べたか

void add_edge(int u, int v){
    G[u].push_back(v); G[v].push_back(u);
}

// 増加パスの探索
bool bp_dfs(int v){
    used[v]=true;
    rep(i,G[v].size()){
        int u=G[v][i], w=match[u];
        if(w<0 || (!used[w]&&bp_dfs(w))){
            match[v]=u; match[u]=v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int ret=0;
    memset(match,-1,sizeof(match));
    rep(i,V){
        if(match[i]<0){
            memset(used,0,sizeof(used));
            if(bp_dfs(i)) ++ret;
        }
    }
    return ret;
}

vector<int> divisor(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

bool same_factor(const vector<int>& a, const vector<int>& b)
{
    int A=a.size(), B=b.size();
    int x=1, y=1;

    while(x<A && y<B)
    {
        if(a[x]>b[y]) ++y;
        else if(a[x]<b[y]) ++x;
        else return true;
    }

    return false;
}

int main()
{
    int m,n;
    while(scanf(" %d %d",&m,&n),m)
    {
        vector<int> b(m),r(n);
        rep(i,m) scanf(" %d", &b[i]);
        rep(i,n) scanf(" %d", &r[i]);

        vector<int> B[500],R[500];
        rep(i,m) B[i] = divisor(b[i]);
        rep(i,n) R[i] = divisor(r[i]);

        V = n+m;
        rep(i,MAX_V) G[i].clear();

        rep(i,m)rep(j,n)
        {
            if(same_factor(B[i],R[j])) add_edge(i,m+j);
        }

        printf("%d\n", bipartite_matching());
    }
    return 0;
}
