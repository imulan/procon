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

const ll INF = 1000000000000000001LL; // 10^18+1

int n;
ll k;
ll a[200000];

inline ll mul(ll x, ll y)
{
    if(y==0) return 0;
    // x*y>INF
    if(x>INF/y) return INF;
    return x*y;
}

// x*p/q
inline ll f(ll x, ll p, ll q)
{
    if(x==0 || p==0) return 0;
    if(x>=INF) return INF;

    ll g = __gcd(x,q);
    x /= g;
    q /= g;
    assert(p%q==0);
    p /= q;
    q /= q;

    return mul(x,p);
}


bool check(ll x)
{
    ll s = 0;
    ll now = 1;
    ll p = x, q = 1;
    for(int i=n-1; i>=0; --i)
    {
        if(a[i]>0)
        {
            s += mul(a[i],now);
            if(s>=k) return true;
        }
        now = f(now,p,q);
        ++p;
        ++q;
    }

    return s>=k;
}

int main()
{
    scanf(" %d %lld", &n, &k);
    rep(i,n) scanf(" %lld", &a[i]);

    ll l=-1,r=k;
    while(r-l>1)
    {
        ll m=(l+r)/2;
        if(check(m)) r=m;
        else l=m;
    }

    printf("%lld\n", r);
    return 0;
}
