#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int MAX_V = 2000;
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


void solve()
{
    // init
    rep(i,MAX_V) G[i].clear();

    int n,c,m;
    cin >>n >>c >>m;

    if(c==2)
    {
        //1以外
        vector<int> a[2];

        int one[2]={}, other[2]={};

        rep(i,m)
        {
            int ID,pos;
            cin >>pos >>ID;
            --ID;

            if(pos==1) ++one[ID];
            else
            {
                a[ID].pb(pos);
                ++other[ID];
            }
        }

        int num = one[0]+one[1];

        int X=a[0].size(), Y=a[1].size();
        V = X+Y;
        rep(i,X)rep(j,Y)
        {
            if(a[0][i] != a[1][j])
            {
                // printf(" ADD %d %d\n", i,X+j);
                add_edge(i, X+j);
            }
        }

        int M = bipartite_matching();

        // マッチングできなかったあまり
        other[0] = max(0,other[0]-M);
        other[1] = max(0,other[1]-M);

        // できるだけ1と合わせる
        if(other[0]>one[1])
        {
            other[0] -= one[1];
            one[1]=0;
        }
        else
        {
            one[1] -= other[0];
            other[0]=0;
        }

        if(other[1]>one[0])
        {
            other[1] -= one[0];
            one[0]=0;
        }
        else
        {
            one[0] -= other[1];
            other[1]=0;
        }

        // 1が余ってたらマッチングを崩す
        while(M>0 && one[0]>0 && one[1]>0)
        {
            --M;
            --one[0];
            --one[1];
        }

        num += M;

        int pro=min(other[0],other[1]);
        num += max(other[0],other[1]);

        printf(" %d %d\n", num,pro);
    }
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        printf("Case #%d:", t+1);
        solve();
    }
    return 0;
}
