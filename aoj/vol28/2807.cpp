#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;

struct edge{int to,cost;};
vector<edge> G[N];

int c[N]={}, d[N]={};
double pw[N];

void dfs(int now, int par, int depth)
{
    d[now] = depth;
    for(edge &e:G[now])
    {
        if(e.to == par) continue;
        
        c[e.to] = e.cost;
        dfs(e.to,now,depth+1);
    }
}

int main()
{
    double p;
    int n;
    scanf(" %lf %d", &p, &n);
    rep(i,n-1)
    {
        int a,b,x;
        scanf(" %d %d %d", &a, &b ,&x);
        --a;
        --b;
        G[a].pb(edge{b,x});
        G[b].pb(edge{a,x});
    }

    dfs(0,-1,0);

    pw[0]=1;
    for(int i=1; i<N; ++i) pw[i]=pw[i-1]*p;

    double A=0,B=1;
    rep(i,n)
    {
        A += c[i]*pw[d[i]];
        B += pw[d[i]];
    }

    printf("%.10f\n", A*B);
    return 0;
}
