#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=100;
const int INF=12345678;
int d[V];

struct edge{int to,cost;};
vector<edge> G[V];

int main()
{
    int n;
    scanf(" %d", &n);
    rep(i,n-1)
    {
        int u,v,c;
        scanf(" %d %d %d", &u, &v, &c);
        G[u].pb({v,c});
        G[v].pb({u,c});
    }

    fill(d,d+V,INF);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        for(const auto &e:G[now])
        {
            if(d[e.to]>d[now]+e.cost)
            {
                d[e.to]=d[now]+e.cost;
                que.push(e.to);
            }
        }
    }

    int ans = 0;
    rep(i,n) ans = max(ans,d[i]);
    printf("%d\n", ans);
    return 0;
}
