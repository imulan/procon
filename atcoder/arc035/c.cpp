#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int INF=12345678;

int main()
{
    int n,m;
    cin >>n >>m;

    int d[400][400];
    fill(d[0],d[400],INF);
    rep(i,n) d[i][i]=0;

    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        d[a][b]=d[b][a]=c;
    }

    rep(k,n)rep(i,n)rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    int Q;
    cin >>Q;
    rep(q,Q)
    {
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);
        --x;
        --y;
        d[x][y]=d[y][x]=min(d[x][y],z);

        //dを更新
        rep(i,n)rep(j,n) d[i][j]=min({d[i][j],d[i][x]+d[x][y]+d[y][j],d[i][y]+d[y][x]+d[x][j]});

        ll ans=0;
        rep(i,n)rep(j,i) ans+=d[j][i];
        cout << ans << endl;
    }

    return 0;
}
