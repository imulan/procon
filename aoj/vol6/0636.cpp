#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,Q;
    ll S,T;
    scanf(" %d %d %lld %lld", &n, &Q, &S, &T);

    vector<ll> a(n+1);
    rep(i,n+1) scanf(" %lld", &a[i]);

    vector<ll> b(n+1);
    ll ans=0;
    rep(i,n)
    {
        b[i] = a[i+1]-a[i];
        if(b[i]>0) ans -= S*b[i];
        else ans -= T*b[i];
    }

    while(Q--)
    {
        int l,r;
        ll x;
        scanf(" %d %d %lld", &l, &r, &x);

        ans += (b[l-1]>0?S:T)*b[l-1];
        b[l-1] += x;
        ans -= (b[l-1]>0?S:T)*b[l-1];

        ans += (b[r]>0?S:T)*b[r];
        b[r] -= x;
        b[n]=0;
        ans -= (b[r]>0?S:T)*b[r];

        printf("%lld\n", ans);
    }
    return 0;
}
