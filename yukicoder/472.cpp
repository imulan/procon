#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=505050505;
const int N=15001;
int dp[N],nx[N];

int p[5000][4];

int main()
{
    int n,P;
    scanf(" %d %d", &n, &P);

    rep(i,n)
    {
        rep(j,3) scanf(" %d", &p[i][j]);
        p[i][3]=1;
    }

    fill(dp,dp+N,INF);
    dp[0]=0;
    rep(i,n)
    {
        fill(nx,nx+N,INF);
        rep(j,N)rep(k,4)if(j+k<N) nx[j+k] = min(nx[j+k],dp[j]+p[i][k]);

        rep(j,N) dp[j]=nx[j];
    }

    printf("%.10f\n", (double)dp[P]/n);
    return 0;
}
