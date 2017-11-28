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

using pi = pair<int,int>;
const int N = 100000;

int n;
vector<int> G[N];

// 帰ってくる必要がある/ない
pi dp1[N];
void dfs(int v, int par)
{
    int res = 0;
    for(int nx:G[v])if(nx!=par)
    {
        dfs(nx,v);
        res += dp1[nx].fi+2;
    }

    int notback = res;
    for(int nx:G[v])if(nx!=par)
    {
        int t = res;
        t -= dp1[nx].fi+2;
        t += dp1[nx].se+1;
        notback = min(notback,t);
    }

    dp1[v] = {res,notback};
}

int dp2[N];
void dfs2(int v, int par, pi d)
{
    vector<pair<pi,int>> c;
    for(int nx:G[v])if(nx!=par) c.pb({dp1[nx],nx});
    c.pb({d,-1});

    int C = c.size();
    int sum = 0;
    rep(i,C) sum += c[i].fi.fi+2;

    // secondを選ぶことによって得られる利益(少ないほうが嬉しい)
    // (利益,頂点)
    vector<pi> gain;

    int ans = sum;
    rep(i,C)
    {
        int t = sum;
        int g = c[i].fi.se+1 - (c[i].fi.fi+2);
        t += g;
        ans = min(ans,t);

        gain.pb({g,c[i].se});
    }
    dp2[v] = ans;

    sort(all(gain));
    // printf(" NOW: v= %d\n", v);
    // rep(i,C) dbg(gain[i]);

    rep(i,C)
    {
        int nx = gain[i].se;
        if(nx==-1) continue;

        pi nd;
        nd.fi = sum - (dp1[nx].fi+2);

        nd.se = nd.fi;
        if(i==0)
        {
            if(C>1) nd.se += gain[1].fi;
        }
        else nd.se += gain[0].fi;

        dfs2(nx,v,nd);
    }
}

int main()
{
    cin >>n;
    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);
    // rep(i,n) printf(" %d:  (%d %d)\n", i,dp1[i].fi,dp1[i].se);

    dfs2(0,-1,{-2,-1});
    rep(i,n) cout << dp2[i] << endl;
    return 0;
}
