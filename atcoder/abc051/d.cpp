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

const int N=100;
const int INF=123456789;
struct edge{ int to,cost; };
vector<edge> G[N];
int d[N],par[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    set<pi> used;
    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        G[a].pb(edge{b,c});
        G[b].pb(edge{a,c});
    }

    rep(i,n)
    {
        fill(d,d+N,INF);
        fill(par,par+N,-1);

        // dijkstra
        priority_queue<pi,vector<pi>,greater<pi>> que;
        d[i]=0;
        que.push(pi(0,i));
        while(!que.empty()){
            pi p=que.top();
            que.pop();
            int v=p.se;
            if(d[v]<p.fi) continue;
            rep(j,G[v].size())
            {
                edge e=G[v][j];
                if(d[e.to]>d[v]+e.cost)
                {
                    d[e.to]=d[v]+e.cost;
                    que.push(pi(d[e.to],e.to));
                    par[e.to]=v;
                }
            }
        }

        rep(j,n)if(i!=j)
        {
            int a=j, b=par[j];
            if(a>b) swap(a,b);
            used.insert(pi(a,b));
        }
    }

    cout << m - used.size() << endl;
    return 0;
}
