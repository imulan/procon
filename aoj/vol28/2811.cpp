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

const int V=100000;
const int N=404040;
const int INF=123456789;

set<int> TIMESET[V];
map<pi,int> v_to_id;

struct edge{int to,cost;};
vector<edge> G[N];
int dist[N];

int main()
{
    int n,m,s,g;
    scanf(" %d %d %d %d", &n, &m, &s, &g);
    --s;
    --g;

    TIMESET[s].insert(0);
    v_to_id[pi(s,0)] = 0;

    int idx=1;

    rep(i,m)
    {
        int u,v,t,c;
        scanf(" %d %d %d %d", &u, &v, &t, &c);
        --u;
        --v;

        TIMESET[u].insert(t);
        TIMESET[v].insert(t+c);

        if(v_to_id.find(pi(u,t)) == v_to_id.end()) v_to_id[pi(u,t)] = idx++;
        if(v_to_id.find(pi(v,t+c)) == v_to_id.end()) v_to_id[pi(v,t+c)] = idx++;

        int S=v_to_id[pi(u,t)], T=v_to_id[pi(v,t+c)];
        G[S].pb(edge{T,0});
    }

    rep(i,n)
    {
        int SZ = TIMESET[i].size();

        auto itr = TIMESET[i].begin();
        rep(j,SZ-1)
        {
            auto nx = itr;
            ++nx;

            int d = *nx - *itr;
            int S=v_to_id[pi(i,*itr)], T=v_to_id[pi(i,*nx)];
            G[S].pb(edge{T,d});

            ++itr;
        }
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push(pi(0,0));
    fill(dist,dist+N,INF);
    dist[0]=0;
    while(!pq.empty())
    {
        pi p=pq.top();
        pq.pop();
        int v=p.se;
        if(dist[v]<p.fi) continue;
        for(edge &e:G[v])
        {
            if(dist[e.to] > dist[v]+e.cost)
            {
                dist[e.to] = dist[v]+e.cost;
                pq.push(pi(dist[e.to],e.to));
            }
        }
    }

    int ans=INF;
    for(const auto &x:TIMESET[g])
    {
        int S = v_to_id[pi(g,x)];
        ans = min(ans,dist[S]);
    }
    printf("%d\n", ans);
    return 0;
}
