#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using ull = unsigned long long;

string x;

string fill_leadingzero(ull n)
{
    string ret=to_string(n);
    while(ret.size()<20) ret = "0"+ret;
    return ret;
}

bool vis[21][10][2][2];
ull dp[21][10][2][2];
// digit, before, leadingzero?, strictly small?
ull dfs(int d, int b, int z, int s)
{
    if(d==20) return 1;
    if(vis[d][b][z][s]) return dp[d][b][z][s];

    ull ret=0;
    if(z==1)
    {
        // 0を続ける
        ret += dfs(d+1,0,1,s|(0<x[d]-'0'));
        // 続けるのをやめる
        int r=9;
        if(s==0) r=x[d]-'0';

        for(int i=1; i<=r; ++i) ret += dfs(d+1,i,0,s|(i<x[d]-'0'));
    }
    else
    {
        for(int i=-1; i<=1; ++i)
        {
            int nx=b+i;
            if(0<=nx && nx<=9)
            {
                if(s==1) ret += dfs(d+1,nx,0,1);
                else
                {
                    if(nx<=x[d]-'0') ret += dfs(d+1,nx,0,(nx<x[d]-'0'));
                }
            }
        }
    }

    vis[d][b][z][s]=true;
    dp[d][b][z][s]=ret;
    return ret;
}

int main()
{
    ull n,k;
    cin >>k >>n;

    x = fill_leadingzero(n);
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    ull under_n = dfs(0,0,1,0);

    ull l=n, r=LLONG_MAX-100;
    while(r-l>1)
    {
        ull m=(l+r)/2;

        x = fill_leadingzero(m);
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        ull val = dfs(0,0,1,0);

        if(val-under_n < k) l=m;
        else r=m;
    }
    cout << r << endl;
    return 0;
}
