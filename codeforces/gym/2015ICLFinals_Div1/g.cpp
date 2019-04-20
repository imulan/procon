#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll cv(ll h, ll m, ll s)
{
    return 1000000000000LL*h + 1000000LL*m + s;
}

void p(ll t)
{
    ll a[3];
    a[0] = t/1000000000000LL;
    t -= 1000000000000LL*a[0];

    a[1] = t/1000000LL;
    t -= 1000000LL*a[1];

    a[2] = t;
    printf("%lld %lld %lld\n", a[0],a[1],a[2]);
}

int main()
{
    int n;
    scanf(" %d", &n);

    vector<ll> t(n);
    rep(i,n)
    {
        int h,m,s;
        scanf(" %d %d %d", &h, &m, &s);
        t[i] = cv(h,m,s);
    }

    sort(all(t));

    ll mod = cv(12,0,0);
    // printf("mod %lld\n", mod);

    ll ans = 0;
    for(int i=1; i<n; ++i)
    {
        ll d = t[0]+mod-t[i];
        ans += d;
    }

    ll T = ans;
    for(int i=1; i<n; ++i)
    {
        T -= mod+t[i-1]-t[i];
        // printf("MINUS %lld\n", mod+t[i-1]-t[i]);
        // p(T);
        T += (n-1)*(t[i]-t[i-1]);
        // p(T);
        ans = min(ans, T);
    }

    p(ans);
}
