#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

const int N = 100000;
vector<int> G[N];
bool vis[N];
int par[N],dep[N];

int p,q;
void dfs(int x){
    vis[x] = true;
    for(int e:G[x])if(e!=par[x]){
        if(vis[e]){
            p=x;
            q=e;
        }
        else{
            dep[e] = dep[x]+1;
            par[e] = x;
            dfs(e);
        }
    }
}

int main(){
    int n;
    cin >>n;

    rep(i,n){
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dep[0] = 0;
    par[0] = -1;
    dfs(0);
    // printf(" (%d %d)\n", p,q);

    vector<bool> cycle(n);
    cycle[p] = cycle[q] = true;

    while(p!=q){
        if(dep[p]>dep[q]){
            p = par[p];
            cycle[p] = true;
        }
        else{
            q = par[q];
            cycle[q] = true;
        }
    }

    int Q;
    cin >>Q;
    rep(i,Q){
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        int ans = 1;
        if(cycle[a] && cycle[b]) ans = 2;
        cout << ans << endl;
    }
    return 0;
}
