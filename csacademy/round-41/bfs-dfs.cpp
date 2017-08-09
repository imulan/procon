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

vector<int> G[5000];
bool vis[5000];

vector<int> bfs()
{
    fill(vis,vis+5000,false);
    vector<int> ret;
    queue<int> que;
    que.push(1);
    vis[1]=true;
    ret.pb(1);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto &e:G[v])
        {
            if(!vis[e])
            {
                que.push(e);
                vis[e] = true;
                ret.pb(e);
            }
        }
    }
    return ret;
}

vector<int> y;
void dfs(int v)
{
    vis[v]=true;
    y.pb(v);
    for(const auto &e:G[v])
    {
        if(!vis[e]) dfs(e);
    }
}

void solve()
{
    int n;
    cin >>n;
    vector<int> b(n),d(n);
    rep(i,n) cin >>b[i];
    rep(i,n) cin >>d[i];

    vector<pi> e;
    for(int i=1; i<n; ++i) e.pb({1,b[i]});
    rep(i,n-1) e.pb({d[i],d[i+1]});

    set<pi> already;
    vector<pi> ans;

    for(const auto &p:e)
    {
        if(!already.count(p))
        {
            ans.pb(p);
            already.insert(p);

            G[p.fi].pb(p.se);
            G[p.se].pb(p.fi);
        }
    }

    vector<int> x = bfs();

    fill(vis,vis+5000,false);
    dfs(1);

    // dbg(x);
    // dbg(y);

    bool ok = true;
    rep(i,n)if(x[i]!=b[i]) ok = false;
    rep(i,n)if(y[i]!=d[i]) ok = false;

    if(ok)
    {
        cout << ans.size() << endl;
        for(const auto &p:ans) printf("%d %d\n", p.fi, p.se);
    }
    else printf("-1\n");
}

int main()
{
    solve();
    return 0;
}
