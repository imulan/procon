#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<ll> x(n),y(m);
    rep(i,n) scanf(" %lld", &x[i]);
    rep(i,m) scanf(" %lld", &y[i]);

    ll X=0,Y=0;

    ll sum=0;
    rep(i,n) (sum+=x[i])%=mod;
    rep(i,n)
    {
        sum-=x[i];
        if(sum<0) sum+=mod;

        (X+=sum)%=mod;
        (X+=(mod-x[i])%mod*(n-1-i))%=mod;
    }

    sum=0;
    rep(i,m) (sum+=y[i])%=mod;
    rep(i,m)
    {
        sum-=y[i];
        if(sum<0) sum+=mod;

        (Y+=sum)%=mod;
        (Y+=(mod-y[i])%mod*(m-1-i))%=mod;
    }

    printf("%lld\n", (X*Y)%mod);
    return 0;
}
