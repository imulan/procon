#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N=100000;
const int INF=12345678;

int p[N]={};
ll a[N]={};

vector<int> G[N];
int d[N];

int main()
{
    int n;
    scanf(" %d", &n);
    for(int i=1; i<n; ++i)
    {
        scanf(" %d", &p[i]);
        --p[i];
        G[i].pb(p[i]);
        G[p[i]].pb(i);
    }
    rep(i,n) scanf(" %lld", &a[i]);

    fill(d,d+N,INF);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        for(const auto &e:G[now])
        {
            if(d[e]>d[now]+1)
            {
                d[e] = d[now]+1;
                que.push(e);
            }
        }
    }

    vector<pi> pp(n);
    rep(i,n) pp[i]=pi(d[i],i);
    sort(all(pp));
    reverse(all(pp));

    rep(i,n)
    {
        int now = pp[i].se;
        a[p[now]] = min(a[p[now]],a[now]);
    }

    vector<bool> vis(n,false);
    vis[0]=true;
    que.push(0);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        for(const auto &e:G[now])
        {
            if(!vis[e])
            {
                a[e] += a[now];
                vis[e]=true;
                que.push(e);
            }
        }
    }

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%lld", a[i]);
    }
    printf("\n");
    return 0;
}
