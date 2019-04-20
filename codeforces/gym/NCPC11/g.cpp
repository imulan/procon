#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 1010;

int main(){
    int n;
    scanf(" %d", &n);

    vector<vector<int>> G(N),rG(N);
    vector<int> xx(n);
    rep(i,n){
        int ID,k;
        scanf(" %d %d", &ID, &k);
        xx[i] = ID;
        rep(j,k){
            int v;
            scanf(" %d", &v);
            G[ID].pb(v);
            rG[v].pb(ID);
        }
    }

    auto BFS = [&](const vector<vector<int>> &g){
        vector<bool> vis(N);
        vis[0]=true;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:g[v]){
                if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                }
            }
        }
        return vis;
    };

    vector<bool> a = BFS(G), b = BFS(rG);
    int ct = 0;
    for(int i:xx){
        if(!b[i]){
            printf("TRAPPED %d\n",i);
            ++ct;
        }
    }
    for(int i:xx){
        if(!a[i]){
            printf("UNREACHABLE %d\n",i);
            ++ct;
        }
    }
    if(ct==0) printf("NO PROBLEMS\n");
    return 0;
}


