#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef vector<int> vi;

vi G[1000];

int main()
{
    int n, m;
    cin >>n >>m;

    vi p(n);
    for(int i=1; i<n; ++i)
    {
        cin >>p[i];
        G[p[i]].pb(i);
    }

    map<int,int> leaf;
    rep(i,m)
    {
        int b,c;
        cin >>b >>c;
        leaf[b]=c;
    }

    vi d(n);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx=G[v][i];
            que.push(nx);
            d[nx]=d[v]+1;
        }
    }

    vector<pi> a(n);
    rep(i,n) a[i]=pi(d[i],i);
    sort(all(a), greater<pi>());

    int ans=0;
    vector<vi> pd(n);
    rep(i,n-1)
    {
        // printf(" %d %d\n", a[i].fi, a[i].se);
        int v=a[i].se;
        if(G[v].size()==0) pd[p[v]].pb(leaf[v]);
        else
        {
            int minpd=12345678;
            rep(j,pd[v].size()) minpd=min(minpd, pd[v][j]);
            rep(j,pd[v].size()) ans+=pd[v][j]-minpd;
            pd[p[v]].pb(minpd);
        }
    }

    rep(i,pd[0].size()) ans+=pd[0][i];

    cout << ans << endl;
    return 0;
}
