#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int V; // TODO:initialize
const int MAX_V = 505; // TODO:initialize
const ll G_INF = LLONG_MAX; // TODO:initialize

ll G[MAX_V][MAX_V];

// O(V^3)
ll global_min_cut(){
    ll ret = G_INF;
    vector<int> redV(V);
    rep(i,V) redV[i] = i;
    for(int r=V; r>1; --r){
        // calc Maximum Adjacent Order
        int u=0, v=0;
        ll cut=0;
        vector<ll> w(r,0);
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

    assert(ret < G_INF && ret >= 0);
    return ret;
}

int main()
{
    int n,m;
    while(~scanf(" %d %d", &n, &m))
    {
        V = n;
        memset(G,0,sizeof(G));

        rep(i,m)
        {
            int a,b;
            ll c;
            scanf(" %d %d %lld", &a, &b, &c);
            G[a][b] += c;
            G[b][a] += c;
        }

        printf("%lld\n", global_min_cut());
    }
    return 0;
}
