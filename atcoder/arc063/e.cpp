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

const int N = 100000;
vector<int> G[N];

const int INF = 19191919;

int root;
int v[N];
int d[N],par[N];

using pi = pair<int,int>;
pi r[N];
int ans[N];

void dfs(int now, pi range, int p)
{
    if(v[now]>=0)
    {
        if(d[now]%2==abs(v[now]-v[root])%2)
        {
            if(p==-1 || abs(v[now]-ans[p])==1) ans[now] = v[now];
        }
    }
    else
    {
        int L = max(range.fi, r[now].fi);
        int R = min(range.se, r[now].se);
        if(L<=R) ans[now] = L;
    }

    if(ans[now]==-INF) return;
    // dbg(now);
    // dbg(ans[now]);
    for(int nx:G[now])if(nx!=p) dfs(nx,{ans[now]-1,ans[now]+1},now);
}

int main()
{
    int n;
    cin >>n;
    rep(i,n-1)
    {
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int k;
    cin >>k;

    fill(v,v+N,-1);
    while(k--)
    {
        int idx,p;
        cin >>idx >>p;
        --idx;
        v[idx]=p;
        root = idx;
    }

    fill(d,d+N,INF);
    fill(par,par+N,-1);
    d[root] = 0;
    queue<int> que;
    que.push(root);
    vector<int> vis;
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        vis.pb(now);

        for(int nx:G[now])
        {
            if(d[nx]>d[now]+1)
            {
                d[nx] = d[now]+1;
                par[nx] = now;
                que.push(nx);
            }
        }
    }

    reverse(all(vis));
    rep(i,n) r[i] = {-INF,INF};
    for(int now:vis)
    {
        if(v[now]!=-1) r[now]={v[now],v[now]};
        int p = par[now];
        if(p!=-1)
        {
            r[p].fi = max(r[p].fi,r[now].fi-1);
            r[p].se = min(r[p].se,r[now].se+1);
        }
    }

    fill(ans,ans+N,-INF);
    dfs(root,{-INF,INF},-1);

    string s = "Yes";
    rep(i,n)if(ans[i]==-INF) s = "No";
    cout << s << endl;
    if(s=="Yes") rep(i,n) cout << ans[i] << endl;
    return 0;
}
