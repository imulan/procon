#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

using pi = pair<int,int>;

const int INF = 123456789;

struct edge{int to,cost;};
const int V = 100000;
vector<edge> G[V];

int main()
{
    int n,m,s,t;
    cin >>n >>m >>s >>t;
    --s;
    --t;

    vector<int> d(n);
    rep(i,n) cin >>d[i];

    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].push_back({b,d[b]});
    }
    // back edge
    rep(i,n-1) G[i+1].push_back({i,0});

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    vector<int> dist(n,INF);
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty())
    {
        pi p = pq.top();
        pq.pop();
        int v = p.second;
        if(p.first>dist[v]) continue;
        for(const auto &e:G[v])
        {
            if(dist[e.to]>dist[v]+e.cost)
            {
                dist[e.to] = dist[v]+e.cost;
                pq.push({dist[e.to],e.to});
            }
        }
    }

    assert(dist[t]<INF);
    cout << dist[t] << endl;
    return 0;
}
