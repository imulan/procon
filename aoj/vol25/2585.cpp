#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using P = pair<int,pi>;

struct edge{int to,cost,time,company;};

const int V=100;
const int INF=123456789;

vector<edge> G[V];

int dp[300];
int d[100][25];

int main()
{
    int N,M,H,K;
    while(scanf(" %d %d %d %d", &N, &M, &H, &K),N)
    {
        rep(i,V) G[i].clear();

        rep(i,M)
        {
            int a,b,c,h,r;
            scanf(" %d %d %d %d %d", &a, &b, &c, &h, &r);
            --a;
            --b;
            --r;
            G[a].pb({b,c,h,r});
            G[b].pb({a,c,h,r});
        }

        int S,T;
        scanf(" %d %d", &S, &T);
        --S;
        --T;

        int PASS;
        scanf(" %d", &PASS);

        vector<int> pass_cost(PASS),mask(PASS);
        rep(i,PASS)
        {
            int l;
            scanf(" %d %d", &l, &pass_cost[i]);

            rep(j,l)
            {
                int k;
                scanf(" %d", &k);
                --k;

                mask[i] |= 1<<k;
            }
        }

        fill(dp,dp+300,INF);
        dp[0]=0;
        rep(i,1<<K)rep(j,PASS)
        {
            int nx = i|mask[j];
            dp[nx] = min(dp[nx],dp[i]+pass_cost[j]);
        }

        int ans=INF;
        rep(i,1<<K)
        {
            if(ans<dp[i]) continue;

            fill(d[0],d[100],INF);
            d[S][0]=0;

            priority_queue<P,vector<P>,greater<P>> pq;
            pq.push(P(0,pi(S,0)));
            while(!pq.empty())
            {
                P now = pq.top();
                pq.pop();

                int v = now.se.fi, h = now.se.se;
                if(now.fi>d[v][h]) continue;

                for(const auto &e:G[v])
                {
                    int nh = h+e.time;
                    if(nh>H) continue;

                    int COST = e.cost;
                    if(i>>e.company&1) COST = 0;

                    if(d[e.to][nh] > d[v][h]+COST)
                    {
                        d[e.to][nh] = d[v][h]+COST;
                        pq.push(P(d[e.to][nh],pi(e.to,nh)));
                    }
                }
            }

            rep(j,H+1) ans = min(ans,d[T][j]+dp[i]);
        }

        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
