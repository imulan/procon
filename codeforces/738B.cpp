#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int a[1000][1000][4]={};
int f[1000][1000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,n)rep(j,m) scanf(" %d", &f[i][j]);

    rep(i,n)
    {
        int now=0;
        rep(j,m)
        {
            if(!f[i][j]) a[i][j][0]=now;
            else now=1;
        }

        now=0;
        for(int j=m-1; j>=0; --j)
        {
            if(!f[i][j]) a[i][j][1]=now;
            else now=1;
        }
    }

    rep(j,m)
    {
        int now=0;
        rep(i,n)
        {
            if(!f[i][j]) a[i][j][2]=now;
            else now=1;
        }

        now=0;
        for(int i=n-1; i>=0; --i)
        {
            if(!f[i][j]) a[i][j][3]=now;
            else now=1;
        }
    }

    int ans = 0;
    rep(i,n)rep(j,m)rep(k,4) ans+=a[i][j][k];
    printf("%d\n", ans);
    return 0;
}
