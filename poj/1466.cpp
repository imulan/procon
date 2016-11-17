#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int MAX_V = 500;
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
    while(cin >>V)
    {
        rep(i,MAX_V) G[i].clear();
        rep(i,V)
        {
            int id,num;
            scanf(" %d: (%d) ",&id, &num);
            rep(j,num)
            {
                int a;
                scanf(" %d", &a);
                if(i<a) add_edge(i,a);
            }
        }

        printf("%d\n", V - bipartite_matching());
    }
    return 0;
}
