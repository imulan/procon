#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

const int INF = 19191919;

struct Store{
    int K;
    vector<int> a,b,c;

    // このお店でi円使って得られる満足度のmax
    ll val[1001];

    Store(int _K, vector<int> _a, vector<int> _b, vector<int> _c)
    {
        K = _k;
        a = _a;
        b = _b;
        c = _c;

        // calc value
        fill(val,val+1001,-INF);
        val[0] = 0;
        rep(i,K)
        {
            rep(j,)

        }
    }
}

Store read_store()
{
    int k;
    cin >>k;
    vector<int> a(k),b(k),c(k);
    rep(i,k) cin >>a[i] >>b[i] >>c[i];
    return Store(k,a,b,c);
}


int n,x,y;
Store s[14];
int d[14][14];

int cost[1<<14];
int dp[1001];

int main()
{
    // input
    cin >>n >>x >>y;
    rep(i,n) s[i] = read_store();
    rep(i,n)rep(j,n) cin >>d[i][j];

    // calc cost


    int ans = 0;

    rep(mask,1<<n)
    {
        fill(dp,dp+1001,-INF);
        dp[0]=0;
    }

    cout << ans << endl;
}
