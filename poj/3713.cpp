// WA
// そもそも求めたいのが辺カットじゃないからダメ

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int V; // TODO:initialize
const int MAX_V = 500; // TODO:initialize
const int G_INF = 12345678; // TODO:initialize

vector< vector<int> > G;

// O(V^3)
int global_min_cut(){
    int ret = G_INF;
    vector<int> redV(V);
    rep(i,V) redV[i] = i;
    for(int r=V; r>1; --r){
        // calc Maximum Adjacent Order
        int u=0, v=0, cut=0;
        vector<int> w(r,0);
        rep(i,r){
            u = v;
            v = max_element(all(w)) - w.begin();
            cut = w[v];
            w[v] = -1;
            rep(nx,r)if(w[nx]>=0) w[nx] += G[redV[v]][redV[nx]];
        }
        // merge
        rep(i,r){
            G[redV[u]][redV[i]] += G[redV[v]][redV[i]];
            G[redV[i]][redV[u]] += G[redV[i]][redV[v]];
        }
        redV.erase(redV.begin()+v);
        // update
        ret = min(ret,cut);
    }
    return ret;
}

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        V = n;
        G = vector< vector<int> >(n,vector<int>(n,0));

        rep(i,m)
        {
            int a,b;
            scanf(" %d %d", &a, &b);
            G[a][b]=G[b][a]=1;
        }

        printf("%s\n", (global_min_cut()>=3)?"YES":"NO");
    }
    return 0;
}
