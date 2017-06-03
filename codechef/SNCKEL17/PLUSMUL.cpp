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

const ll mod=1e9+7;

ll solve()
{
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    ll x = a[0], y = 0, z = 1;
    for(int i=1; i<n; ++i)
    {
        y = (y*2+x)%mod;
        x = (x*a[i]+a[i]*z%mod)%mod;
        z = (z*2)%mod;
    }
    return (x+y)%mod;
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) printf("%lld\n", solve());
    return 0;
}
