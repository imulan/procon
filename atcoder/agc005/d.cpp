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

const ll mod=924844033;

ll dp[4002][2002][2]={0};
ll fact[2001];

int main()
{
    fact[0]=1;
    for(ll i=1; i<=2000; ++i) fact[i]=(i*fact[i-1])%mod;

    int n,k;
    cin >>n >>k;

    vector<bool> vis(2*n,false);
    vector<pi> edge;
    vector<bool> conneced_prev;
    rep(i,n)
    {
        if(vis[i]) continue;

        int ii=i;
        int jj=i-k;
        if(jj<0) jj+=2*k;

        if(jj>=n) continue;

        edge.pb(pi(ii,jj));
        conneced_prev.pb(false);
        while(1)
        {
            if(ii<jj) ii+=2*k;
            else jj+=2*k;

            if(ii>=n || jj>=n) break;

            edge.pb(pi(ii,jj));
            conneced_prev.pb(true);
            vis[ii]=vis[jj+n]=true;
        }
    }

    int E=edge.size();
    
    dp[0][0][0]=1;
    rep(i,E)
    {
        rep(j,min(2001,i+1))
        {
            // i番目の辺を使う
            (dp[i+1][j+1][1] += dp[i][j][0]) %= mod;
            if(!conneced_prev[i]) (dp[i+1][j+1][1] += dp[i][j][1]) %= mod;

            // i番目の辺を使わない
            (dp[i+1][j][0] += dp[i][j][0]+dp[i][j][1]) %= mod;
        }
    }

    vector<ll> M(E+1);
    rep(i,E+1) M[i] = (dp[E][i][0]+dp[E][i][1])%mod;

    ll sub=0;
    for(int i=1; i<=min(E,n); ++i)
    {
        if(i%2==0) sub = (sub - (M[i]*fact[n-i])%mod + mod)%mod;
        else sub = (sub + (M[i]*fact[n-i])%mod)%mod;
    }

    ll ans=(fact[n]-sub+mod)%mod;
    cout << ans << endl;
    return 0;
}
