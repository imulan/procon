#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int MAX_V = 5000;
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

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int r,c;
    cin >>r >>c;
    vector<string> f(r);
    rep(i,r) cin >>f[i];

    int a[50][50]={}, b[50][50]={};

    int now=1;

    rep(i,r)rep(j,c)
    {
        if(f[i][j]=='*')
        {
            a[i][j]=now;
            if(j==c-1) ++now;
            else
            {
                if(f[i][j+1]=='.') ++now;
            }
        }
    }
    rep(j,c)rep(i,r)
    {
        if(f[i][j]=='*')
        {
            b[i][j]=now;
            if(i==r-1) ++now;
            else
            {
                if(f[i+1][j]=='.') ++now;
            }
        }
    }

    // rep(i,r)
    // {
    //     rep(j,c) printf("%2d", a[i][j]);
    //     printf("\n");
    // }
    // printf("\n");
    // rep(i,r)
    // {
    //     rep(j,c) printf("%2d", b[i][j]);
    //     printf("\n");
    // }

    V=now+1;
    rep(i,r)rep(j,c)
    {
        if(f[i][j]=='*') add_edge(a[i][j],b[i][j]);
    }
    printf("%d\n",bipartite_matching());
    return 0;
}
