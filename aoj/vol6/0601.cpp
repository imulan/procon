#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using P = pair<ll,int>;

struct edge{int to; ll cost;};
const int V=100000;
const int VV=800000;
const ll INF=LLONG_MAX/3;

vector<edge> G[V],gg[VV];
set<int> height[V];

int n,m;
ll X;
int H[V];

map<pi,int> v2id;
int max_h[V]={};

ll d[VV];

int main()
{
    scanf(" %d %d %lld", &n, &m, &X);
    rep(i,n) scanf(" %d", &H[i]);
    rep(i,m)
    {
        int a,b,t;
        scanf(" %d %d %d", &a, &b, &t);
        --a;
        --b;
        G[a].pb({b,t});
        G[b].pb({a,t});
    }

    int ct=1;

    priority_queue<pi> que;
    que.push(pi(X,0));
    v2id[pi(0,X)]=0;
    max_h[0]=X;
    height[0].insert(X);
    while(!que.empty())
    {
        pi p = que.top();
        que.pop();

        int v=p.se, h=p.fi;
        if(h<max_h[v]) continue;

        for(const auto &e:G[v])
        {
            int bh = h;
            int nh = h-e.cost;

            if(nh<0) continue;

            if(nh>H[e.to])
            {
                bh = H[e.to]+e.cost;
                nh = H[e.to];
            }

            if(nh>max_h[e.to])
            {
                if(!v2id.count(pi(v,bh)))
                {
                    v2id[pi(v,bh)] = ct++;
                    height[v].insert(bh);
                }
                if(!v2id.count(pi(e.to,nh)))
                {
                    v2id[pi(e.to,nh)] = ct++;
                    height[e.to].insert(nh);
                }

                int uu=v2id[pi(v,bh)], vv=v2id[pi(e.to,nh)];
                gg[uu].pb({vv,e.cost});

                max_h[e.to]=nh;
                que.push(pi(max_h[e.to],e.to));
            }
        }
    }

    // 最低限
    rep(i,n)for(const auto &e:G[i])
    {
        if(H[i]<e.cost) continue;

        if(!v2id.count(pi(i,e.cost)))
        {
            v2id[pi(i,e.cost)] = ct++;
            height[i].insert(e.cost);
        }
        if(!v2id.count(pi(e.to,0)))
        {
            v2id[pi(e.to,0)] = ct++;
            height[e.to].insert(0);
        }

        int uu = v2id[pi(i,e.cost)];
        int vv = v2id[pi(e.to,0)];
        gg[uu].pb({vv,e.cost});
    }

    // ゴール
    if(!v2id.count(pi(n-1,H[n-1])))
    {
        v2id[pi(n-1,H[n-1])] = ct++;
        height[n-1].insert(H[n-1]);
    }

    rep(i,n)
    {
        int S = height[i].size();

        auto itr = height[i].begin();
        rep(j,S-1)
        {
            auto nx = itr;
            ++nx;

            assert(v2id.count(pi(i,*itr)));
            assert(v2id.count(pi(i,*nx)));

            int uu = v2id[pi(i,*itr)];
            int vv = v2id[pi(i,*nx)];
            int dist = *nx - *itr;

            gg[uu].pb({vv,dist});
            gg[vv].pb({uu,dist});

            itr = nx;
        }
    }

    // gg上でdijkstra
    int start = v2id[pi(0,X)];
    int goal = v2id[pi(n-1,H[n-1])];
    fill(d,d+VV,INF);
    d[start]=0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(pi(0,start));
    while(!pq.empty())
    {
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[v]) continue;
        for(const auto &e:gg[v])
        {
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                pq.push(pi(d[e.to],e.to));
            }
        }
    }

    ll ans = d[goal];
    if(ans==INF) ans=-1;
    printf("%lld\n", ans);
    return 0;
}
