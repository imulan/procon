#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<ll,int> P;
struct edge{int to; ll cost;};

const ll INF = 1234567890123456LL;

vector<edge> G[100000];
ll dist[100000];
ll cost[100000];

int main()
{
    int n,m,k,s;
    ll p,q;
    cin >>n >>m >>k >>s;
    cin >>p >>q;

    vector<int> c(k);
    vector<pi> ed(m);
    rep(i,k)
    {
        scanf(" %d", &c[i]);
        --c[i];
    }
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d",&a,&b);
        --a;
        --b;

        ed[i]=pi(a,b);

        G[a].pb(edge{b,1});
        G[b].pb(edge{a,1});
    }

    priority_queue<P,vector<P>,greater<P>> que;

    //支配されている街からの最短距離を求める
    fill(dist,dist+n,INF);
    rep(i,k)
    {
        dist[c[i]]=0;
        que.push(P(0,c[i]));
    }
    while(!que.empty())
    {
        P now=que.top();
        que.pop();
        int v=now.se;
        if(dist[v]<now.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(dist[e.to] > dist[v]+e.cost)
            {
                dist[e.to]=dist[v]+e.cost;
                que.push(pi(dist[e.to],e.to));
            }
        }
    }

    //rep(i,n) printf("%d : %lld\n", i+1,dist[i]);

    //辺を追加し直す
    rep(i,n) G[i].clear();
    rep(i,m)
    {
        int a=ed[i].fi, b=ed[i].se;

        //支配されているのでこの辺は張らない
        if(dist[a]==0 || dist[b]==0) continue;

        //ゴールにつながる辺のコストは0
        if(a==n-1 || b==n-1)
        {
            G[a].pb(edge{b,0});
            G[b].pb(edge{a,0});
        }
        else
        {
            //aが危険ならaへ入る辺のコストはq
            if(dist[a]<=s) G[b].pb(edge{a,q});
            else G[b].pb(edge{a,p});
            //bも同様
            if(dist[b]<=s) G[a].pb(edge{b,q});
            else G[a].pb(edge{b,p});
        }
    }

    fill(cost,cost+n,INF);
    cost[0]=0;
    que.push(P(0,0));
    while(!que.empty())
    {
        P now=que.top();
        que.pop();
        int v=now.se;
        if(cost[v]<now.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(cost[e.to] > cost[v]+e.cost)
            {
                cost[e.to]=cost[v]+e.cost;
                que.push(P(cost[e.to],e.to));
            }
        }
    }

    cout << cost[n-1] << endl;
    return 0;
}
