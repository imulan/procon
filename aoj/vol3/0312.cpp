#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[1<<15]={};

int main()
{
    int m,n;
    scanf(" %d %d", &m, &n);
    vector<int> w(m),t(m),W(n),T(n);
    rep(i,m) scanf(" %d %d", &w[i], &t[i]);
    rep(i,n) scanf(" %d %d", &W[i], &T[i]);

    vector<int> sumw(m+1),sumt(m+1);
    rep(i,m)
    {
        sumw[i+1] = sumw[i]+w[i];
        sumt[i+1] = sumt[i]+t[i];
    }

    rep(mask,1<<n)
    {
        // 次に使う段を選ぶ
        rep(i,n)if(!(mask>>i&1))
        {
            int nmask = mask | 1<<i;
            int s=dp[mask];
            int widx = upper_bound(all(sumw),W[i]+sumw[s])-sumw.begin()-1;
            int tidx = upper_bound(all(sumt),T[i]+sumt[s])-sumt.begin()-1;

            dp[nmask] = max(dp[nmask],min(widx,tidx));
        }
    }

    printf("%d\n", dp[(1<<n)-1]);
    return 0;
}
