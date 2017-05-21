#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int h,w;
int f[10][10];

int ct;
int x[24],y[24];

unordered_map<int,int> dp;
int dfs(int s)
{
    if(dp.count(s)) return dp[s];

    int mask = s>>5;
    int now = s&31;

    vector<int> nx;
    int X=x[now], Y=y[now];

    X = x[now]+1;
    while(X<w)
    {
        if(f[Y][X]>0)
        {
            if(!(mask>>f[Y][X]&1))
            {
                nx.pb(f[Y][X]);
                break;
            }
        }
        ++X;
    }
    X = x[now]-1;
    while(X>=0)
    {
        if(f[Y][X]>0)
        {
            if(!(mask>>f[Y][X]&1))
            {
                nx.pb(f[Y][X]);
                break;
            }
        }
        --X;
    }

    X = x[now];
    Y = y[now]+1;
    while(Y<h)
    {
        if(f[Y][X]>0)
        {
            if(!(mask>>f[Y][X]&1))
            {
                nx.pb(f[Y][X]);
                break;
            }
        }
        ++Y;
    }
    Y = y[now]-1;
    while(Y>=0)
    {
        if(f[Y][X]>0)
        {
            if(!(mask>>f[Y][X]&1))
            {
                nx.pb(f[Y][X]);
                break;
            }
        }
        --Y;
    }

    // finish
    if(mask == (1<<ct)-1-1)
    {
        if(x[now]==x[0] || y[now]==y[0]) return 1;
        else return 0;
    }

    int ret=0;
    for(const auto &p:nx)
    {
        if(p==0) continue;

        int nmask = mask|(1<<p);
        int nxt = (nmask<<5) | p;
        ret += dfs(nxt);
    }

    dp[s]=ret;
    return ret;
}

int main()
{
    while(scanf(" %d %d", &w, &h),h)
    {
        ct=1;
        rep(i,h)rep(j,w)
        {
            scanf(" %d", &f[i][j]);
            if(f[i][j]==1)
            {
                f[i][j] = ct;
                x[ct] = j;
                y[ct] = i;
                ++ct;
            }
            else if(f[i][j]==2)
            {
                f[i][j] = 0;
                x[0] = j;
                y[0] = i;
            }
            else f[i][j]=-1;
        }

        dp.clear();
        printf("%d\n", dfs(0));
    }
    return 0;
}
