#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int V; // TODO:initialize
const int MAX_V = 150; // TODO:initialize
const int G_INF = 12345678; // TODO:initialize

vector<vector<int>> G;

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

int solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    V = n;
    G = vector<vector<int>>(n,vector<int>(n,0));
    rep(i,m)
    {
        int u,v,c;
        scanf(" %d %d %d", &u, &v, &c);
        --u;
        --v;
        G[u][v]=G[v][u]=c;
    }
    return global_min_cut();
}

int main()
{
    int T;
    scanf(" %d", &T);
    rep(i,T) printf("Case #%d: %d\n", i+1, solve());
    return 0;
}
