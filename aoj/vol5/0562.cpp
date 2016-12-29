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

const int V=3000;
const int INF=1010101010;

struct edge{int to,cost;};
vector<edge> G[V];
int d[V];

int main()
{
    int N,M,K;
    scanf(" %d %d %d", &N, &M, &K);

    vector<int> a(M),b(M),c(M);
    rep(i,M)
    {
        scanf(" %d %d %d", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        G[a[i]].pb(edge{b[i],c[i]});
        G[b[i]].pb(edge{a[i],c[i]});
    }

    fill(d,d+V,INF);
    priority_queue<pi,vector<pi>,greater<pi>> que;

    rep(i,K)
    {
        int s;
        scanf(" %d", &s);
        --s;
        d[s]=0;
        que.push(pi(0,s));
    }

    while(!que.empty()){
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[v]<p.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(pi(d[e.to],e.to));
            }
        }
    }

    double ans=0;

    rep(i,N) ans=max(ans,d[i]*1.0);
    rep(i,M)
    {
        double s=(d[b[i]]+c[i]-d[a[i]])/2.0;
        if(0<=s && s<=c[i]) ans=max(ans, d[a[i]]+s);
    }

    printf("%d\n", (int)(ans+0.5));
    return 0;
}
