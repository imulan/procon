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

vector<int> invG[100000];

int main()
{
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        --a[i];
    }

    for(int i=1; i<n; ++i) invG[a[i]].pb(i);

    vector<int> d(n,0);
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,invG[v].size())
        {
            int nx=invG[v][i];
            d[nx]=d[v]+1;
            que.push(nx);
        }
    }

    vector<pi> p(n);
    rep(i,n) p[i]=pi(d[i],i);
    sort(all(p), greater<pi>());

    int ans=0;
    if(a[0]!=0)
    {
        ++ans;
        a[0]=0;
    }

    vector<bool> vis(n,false);
    rep(i,n)
    {
        int v=p[i].se;
        if(p[i].fi<=k) break;
        if(vis[v]) continue;

        int r=v;
        rep(j,k-1) r=a[r];

        //おわり
        if(r==0) break;

        ++ans;
        que.push(r);
        vis[r]=true;
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            rep(j,invG[now].size())
            {
                int nx=invG[now][j];
                if(!vis[nx])
                {
                    vis[nx]=true;
                    que.push(nx);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
