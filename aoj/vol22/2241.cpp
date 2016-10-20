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

int check(const vector<vector<int>> &z)
{
    int Z=z.size();
    if(Z==1) return z[0][0];

    int ret=0;
    rep(i,Z)
    {
        bool ok=true;
        rep(j,Z)
        {
            if(z[i][j]==0) ok=false;
        }
        if(ok) ++ret;
    }
    rep(i,Z)
    {
        bool ok=true;
        rep(j,Z)
        {
            if(z[j][i]==0) ok=false;
        }
        if(ok) ++ret;
    }

    bool ok=true;
    rep(i,Z)
    {
        if(z[i][i]==0) ok=false;
    }
    if(ok) ++ret;

    ok=true;
    rep(i,Z)
    {
        if(z[i][Z-1-i]==0) ok=false;
    }
    if(ok) ++ret;

    return ret;
}


int main()
{
    int n,m,win[2];
    int num[100000];

    map<int,pi> f[2];

    scanf(" %d %d %d %d", &n, &win[0], &win[1], &m);
    rep(i,2)rep(j,n)rep(k,n)
    {
        int c;
        scanf(" %d", &c);
        f[i][c] = pi(j,k);
    }
    rep(i,m) scanf(" %d", &num[i]);

    int l=-1,r=m;
    while(r-l>1)
    {
        int mid=(l+r)/2;

        vector<vector<int>> v[2];
        rep(i,2) v[i]=vector<vector<int>>(n,vector<int>(n,0));

        rep(i,mid+1)
        {
            rep(j,2)if(f[j].find(num[i]) != f[j].end())
            {
                pi p=f[j][num[i]];
                v[j][p.fi][p.se]=1;
            }
        }

        int a[2];
        rep(i,2) a[i]=check(v[i]);

        if(win[0]<=a[0] || win[1]<=a[1]) r=mid;
        else l=mid;
    }

    string ans="DRAW";
    if(r<m)
    {
        vector<vector<int>> v[2];
        rep(i,2) v[i]=vector<vector<int>>(n,vector<int>(n,0));

        rep(i,r+1)
        {
            rep(j,2)if(f[j].find(num[i]) != f[j].end())
            {
                pi p=f[j][num[i]];
                v[j][p.fi][p.se]=1;
            }
        }

        int a[2];
        rep(i,2) a[i]=check(v[i]);

        if(win[0]<=a[0] && win[1]<=a[1]) ans="DRAW";
        else
        {
            if(win[0]<=a[0]) ans="USAGI";
            if(win[1]<=a[1]) ans="NEKO";
        }
    }

    cout << ans << endl;
    return 0;
}
