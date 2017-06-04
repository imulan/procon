#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;

int n,L,A,B;
int s[N];

ll f(ll x)
{
    ll ret=0;
    ll pos = x;
    rep(i,n)
    {
        ret += abs(pos-s[i]);
        pos += L;
    }
    return ret;
}

ll solve()
{
    scanf(" %d %d %d %d", &n, &L, &A, &B);
    rep(i,n) scanf(" %d", &s[i]);
    sort(s,s+n);

    ll l=A, r=B-n*L;
    rep(loop,60)
    {
        ll x1 = (2*l+r)/3, x2 = (l+2*r)/3;
        if(f(x1)>f(x2)) l=x1;
        else r=x2;
    }

    ll ret=LLONG_MAX;
    for(ll i=l; i<=r; ++i) ret = min(ret,f(i));
    return ret;
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) printf("%lld\n", solve());
    return 0;
}
