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

const int M = 101;
const int INF = 19191919;

// トレーニングをi種類行った時、消費体力がjの時における消費カロリーのmax
int maxcal[M][M];

// 摂取カロリーがiの時の得られる幸福度のmax
const int H = 10001;
int maxh[H]={};

// i日経過した時に体力がjにおける、幸福度のmax
int dp[M][M];


int main()
{
    int S,T,U,N,O,D;
    cin >>S >>T >>U >>N >>O >>D;

    vector<int> e(T),c(T),h(N),a(N);
    rep(i,T) cin >>e[i] >>c[i];
    rep(i,N) cin >>h[i] >>a[i];

    fill(maxcal[0],maxcal[M],-INF);
    maxcal[0][0] = 0;
    rep(i,T)for(int j=M-2; j>=0; --j)rep(k,M)
    {
        int cost = k+e[i];
        if(cost<M) maxcal[j+1][cost] = max(maxcal[j+1][cost], maxcal[j][k]+c[i]);
    }

    rep(i,N)rep(j,H)
    {
        int nj = j+a[i];
        if(nj<H) maxh[nj] = max(maxh[nj], maxh[j]+h[i]);
    }
    for(int i=1; i<H; ++i) maxh[i] = max(maxh[i],maxh[i-1]);

    fill(dp[0],dp[M],-INF);
    dp[0][S] = 0;
    // i日目,体力j
    rep(i,D)rep(j,S+1)
    {
        // 体力をk消費してトレーニングする
        rep(k,j+1)
        {
            int cal = maxcal[U][k];
            if(cal<0) continue;
            dp[i+1][min(j-k+O,S)] = max(dp[i+1][min(j-k+O,S)], dp[i][j]+maxh[cal]);
        }
    }

    int ans = -1;
    rep(i,M) ans = max(ans,dp[D][i]);
    cout << ans << endl;
    return 0;
}
