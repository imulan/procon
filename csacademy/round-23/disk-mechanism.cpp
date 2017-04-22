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
    int n;
    scanf(" %d", &n);
    vector<ll> x(n),a(n),b(n);
    rep(i,n) scanf(" %lld", &x[i]);
    rep(i,n) scanf(" %lld %lld", &a[i], &b[i]);

    vector<ll> d(n-1);
    rep(i,n-1) d[i]=x[i+1]-x[i];

    ll A=a[0], B=b[0];
    ll D=0;
    for(int i=1; i<n; ++i)
    {
        D = -D + d[i-1];
        ll l,r;
        if(i%2)
        {
            l = D-b[i];
            r = D-a[i];
        }
        else
        {
            l = a[i]-D;
            r = b[i]-D;
        }

        A = max(A,l);
        B = min(B,r);
    }

    printf("%lld\n", max<ll>(0,B-A+1));
    return 0;
}
