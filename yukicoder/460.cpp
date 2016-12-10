#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF=123456789;

int main()
{
    int m,n;
    scanf(" %d %d", &m, &n);

    vvi a(m,vi(n));
    rep(i,m)rep(j,n) scanf(" %d", &a[i][j]);

    #define IN(x,y) (0<=x && x<n && 0<=y && y<m)
    int ans=INF;
    rep(mask,1<<(n+m-1))
    {
        vvi b(a);

        int ct=0;
        rep(i,n)if((mask>>i)&1)
        {
            ++ct;
            for(int x=i-1; x<=i+1; ++x)for(int y=-1; y<=1; ++y)if(IN(x,y)) b[y][x] = !b[y][x];
        }
        for(int i=1; i<m; ++i)if((mask>>(n+i-1))&1)
        {
            ++ct;
            for(int x=-1; x<=1; ++x)for(int y=i-1; y<=i+1; ++y)if(IN(x,y)) b[y][x] = !b[y][x];

        }

        for(int i=1; i<m; ++i)for(int j=1; j<n; ++j)if(b[i-1][j-1])
        {
            ++ct;
            for(int x=j-1; x<=j+1; ++x)for(int y=i-1; y<=i+1; ++y)if(IN(x,y)) b[y][x] = !b[y][x];
        }

        bool all_zero=true;
        rep(i,m)rep(j,n)if(b[i][j]!=0) all_zero=false;
        if(all_zero) ans=min(ans,ct);
    }

    if(ans==INF) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}
