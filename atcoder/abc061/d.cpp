#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=1000;
const ll INF=LLONG_MAX/3;

int n,m;
struct edge{int to,cost;};
vector<edge> G[N];
ll d[N];

bool find_loop()
{
    set<int> v;
    fill(d,d+N,-INF);
    d[0]=0;
    rep(i,n)rep(j,n)for(const auto &e:G[j])
    {
        if(d[e.to] < d[j]+e.cost)
        {
            d[e.to] = d[j]+e.cost;
            if(i==n-1) v.insert(e.to);
        }
    }

    vector<bool> vis(n,false);
    queue<int> que;
    for(auto &x:v)
    {
        que.push(x);
        vis[x]=true;
    }
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        for(const auto &e:G[now])
        {
            if(!vis[e.to])
            {
                vis[e.to] = true;
                que.push(e.to);
            }
        }
    }

    return vis[n-1];
}

int main()
{
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        G[a].pb({b,c});
    }

    if(find_loop()) printf("inf\n");
    else printf("%lld\n", d[n-1]);
    return 0;
}
