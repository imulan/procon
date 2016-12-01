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

typedef vector<int> vi;

inline vi convert(string s)
{
    vector<int> ret;

    int a=0,b=0;
    bool two=false;
    int S=s.size();
    rep(i,S)
    {
        if(s[i]=='*')
        {
            two=true;
            b|=(1<<i);
        }
        else if(s[i]=='1')
        {
            a|=(1<<i);
            b|=(1<<i);
        }
    }

    ret.pb(a);
    if(two) ret.pb(b);

    return ret;

}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m;
    while(cin >>n >>m,n)
    {
        rep(i,MAX_V) G[i].clear();

        vi odd,even;

        rep(i,m)
        {
            string op;
            cin >>op;

            vi tmp=convert(op);
            rep(j,tmp.size())
            {
                int cheese=tmp[j];
                if(__builtin_popcount(cheese)%2==0) even.pb(cheese);
                else odd.pb(cheese);
            }
        }

        sort(all(odd));
        odd.erase(unique(all(odd)),odd.end());
        sort(all(even));
        even.erase(unique(all(even)),even.end());

        int O=odd.size(), E=even.size();
        V=O+E;

        rep(i,odd.size())rep(j,even.size())
        {
            int a=odd[i],b=even[j];
            if(__builtin_popcount(a^b)==1) add_edge(i,j+O);
        }

        printf("%d\n", O+E-bipartite_matching());
    }
    return 0;
}
