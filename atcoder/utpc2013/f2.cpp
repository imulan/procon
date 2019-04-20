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

const int N = 1010;
const ll INF = LLONG_MAX/3;

int n;
int x[N],y[N],d[N],c[N];

inline ll sq(ll a){ return a*a; }
inline ll dist2(int a, int b){ return sq(x[a]-x[b]) + sq(y[a]-y[b]); }

vector<int> G[N];
ll dp[N][3000];
ll dfs(int v, int r, int p)
{
    if(dp[v][r]>=0) return dp[v][r];

    ll ret = INF;
    // 頂点 v の強化幅
    rep(i,3000)if(sq(d[p]+r+d[v]+i) >= dist2(p,v) )
    {
        ll t = c[v]*i;
        if(t>ret) break;
        // printf(" v %d, i %d\n", v,i);
        for(int nx:G[v])if(nx!=p)
        {
            t += dfs(nx,i,v);
        }
        ret = min(ret,t);
    }

    return dp[v][r] = ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>x[i] >>y[i];
    rep(i,n) cin >>d[i] >>c[i];

    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    G[n].pb(0);
    x[n]=x[0];
    y[n]=y[0];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,n) << endl;
    return 0;
}
