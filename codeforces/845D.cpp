#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int INF = 19191919;

const int S = 303;
int dp[S][2], nx[S][2];

int main()
{
    int n;
    scanf(" %d", &n);

    fill(dp[0],dp[S],INF);
    dp[300][1] = 0;
    int sp=0;

    rep(i,n)
    {
        fill(nx[0],nx[S],INF);

        int t,s=-1;
        scanf(" %d", &t);
        if(t==1 || t==3) scanf(" %d", &s);

        rep(j,S)rep(k,2)if(dp[j][k]<INF)
        {
            if(t==1)
            {
                sp=s;
                if(sp<=j) nx[j][k] = min(nx[j][k],dp[j][k]);
            }
            else if(t==2)
            {
                if(k==1) nx[j][k] = min(nx[j][k],dp[j][k]);
            }
            else if(t==3)
            {
                // 見た
                if(sp<=s) nx[s][k] = min(nx[s][k],dp[j][k]);
                // 無視
                nx[j][k] = min(nx[j][k],dp[j][k]+1);
            }
            else if(t==4)
            {
                nx[j][1] = min(nx[j][1],dp[j][k]);
            }
            else if(t==5)
            {
                nx[300][k] = min(nx[300][k],dp[j][k]);
            }
            else
            {
                // 見た
                nx[j][0] = min(nx[j][0],dp[j][k]);
                // 無視
                nx[j][k] = min(nx[j][k],dp[j][k]+1);
            }
        }

        rep(j,S)rep(k,2) dp[j][k]=nx[j][k];
        // rep(j,S)rep(k,2)if(dp[j][k]<INF) printf(" (%d %d): %d\n", j,k,dp[j][k]);
    }

    int ans = INF;
    rep(i,S)rep(j,2) ans = min(ans,dp[i][j]);
    printf("%d\n", ans);
    return 0;
}
