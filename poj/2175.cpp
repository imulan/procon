#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

void solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(n),y(n),b(n);
    rep(i,n) scanf(" %d %d %d", &x[i], &y[i], &b[i]);
    vector<int> p(m),q(m),c(m);
    rep(i,m) scanf(" %d %d %d", &p[i], &q[i], &c[i]);

    int E[100][100];
    rep(i,n)rep(j,m) scanf(" %d", &E[i][j]);

    const int N=201;
    const int INF=19191919;
    int g[N][N],prev[N][N];
    bool used[N];

    int V = n+m+1;

    rep(i,V) fill(g[i],g[i]+V,INF);
    rep(j,m)
    {
        int sum = 0;
        rep(i,n)
        {
            int cost = abs(x[i]-p[j])+abs(y[i]-q[j])+1;

            // 辺を張る
            g[i][n+j] = cost;
            // 流量があれば逆辺ができる
            if(E[i][j]>0) g[n+j][i] = -cost;

            sum += E[i][j];
        }

        // 流量があればsinkからの逆辺ができる
        if(sum>0) g[n+m][n+j]=0;
        // 流量がシェルターの容量一杯でなければsinkへの辺が残る
        if(sum<c[j]) g[n+j][n+m]=0;

    }

    // Floyd-Warshallによふ負閉路検出
    rep(i,V)rep(j,V) prev[i][j]=i;
    rep(k,V)rep(i,V)rep(j,V)
    {
        if(g[i][j] > g[i][k]+g[k][j])
        {
            g[i][j] = g[i][k]+g[k][j];
            prev[i][j] = prev[k][j];

            // 負閉路
            if(i==j && g[i][i]<0)
            {
                fill(used,used+V,false);
                for(int v=i; !used[v]; v=prev[i][v])
                {
                    used[v]=true;
                    if(v!=n+m && prev[i][v]!=n+m)
                    {
                        if(v>=n) ++E[prev[i][v]][v-n];
                        else --E[v][prev[i][v]-n];
                    }
                }
                printf("SUBOPTIMAL\n");
                rep(ii,n)rep(jj,m) printf("%d%c", E[ii][jj], (jj==m-1?'\n':' '));
                return;
            }

        }
    }

    printf("OPTIMAL\n");
}

int main()
{
    solve();
    return 0;
}
