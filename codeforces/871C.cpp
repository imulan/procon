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

const ll mod = 1e9+7;
const int N = 222222;

ll pw[N];

vector<int> G[N];
bool vis[N]={};
int cv;
set<pi> ce;
void dfs(int v)
{
    vis[v] = true;
    ++cv;
    for(int e:G[v])
    {
        ce.insert({min(e,v),max(e,v)});
        if(!vis[e]) dfs(e);
    }
}

int main()
{
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*2)%mod;

    int n;
    scanf(" %d", &n);

    vector<int> x(n),y(n),xx,yy;
    rep(i,n)
    {
        scanf(" %d %d", &x[i], &y[i]);
        xx.pb(x[i]);
        yy.pb(y[i]);
    }

    sort(all(xx));
    xx.erase(unique(all(xx)),xx.end());
    sort(all(yy));
    yy.erase(unique(all(yy)),yy.end());

    int a = xx.size(), b = yy.size();
    rep(i,n)
    {
        int vx = lower_bound(all(xx),x[i])-xx.begin();
        int vy = lower_bound(all(yy),y[i])-yy.begin()+a;

        G[vx].pb(vy);
        G[vy].pb(vx);
    }

    ll ans = 1;
    rep(i,a+b)
    {
        if(vis[i]) continue;
        cv = 0;
        ce.clear();

        dfs(i);
        int E = ce.size();
        if(E>=cv) (ans*=pw[cv])%=mod;
        else (ans*=pw[cv]-1)%=mod;
    }

    printf("%lld\n", ans);
    return 0;
}
