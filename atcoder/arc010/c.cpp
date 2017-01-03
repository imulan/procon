#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m,Y,Z;
char c[10];
int p[10];
string b;

int f[30];

const int INF=123456789;

int dp[1024][11];
int nx[1024][11];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cin >>n >>m >>Y >>Z;
    rep(i,m)
    {
        cin >>c[i] >>p[i];
        f[c[i]-'A']=i;
    }
    cin >>b;

    fill(dp[0],dp[1024],-INF);
    dp[0][m]=0;

    rep(i,n)
    {
        fill(nx[0],nx[1024],-INF);

        rep(mask,1<<m)rep(col,m+1)
        {
            if(dp[mask][col]==-INF) continue;

            nx[mask][col]=max(nx[mask][col],dp[mask][col]);

            int nc=f[b[i]-'A'];
            nx[mask|(1<<nc)][nc] = max(nx[mask|(1<<nc)][nc], dp[mask][col]+p[nc]+((col==nc)?Y:0));
        }

        rep(j,1<<m)rep(k,m+1) dp[j][k]=nx[j][k];
    }

    int ans=0;
    rep(mask,1<<m)rep(col,m+1) ans = max(ans, dp[mask][col]+((mask==((1<<m)-1))?Z:0));
    cout << ans << endl;
    return 0;
}
