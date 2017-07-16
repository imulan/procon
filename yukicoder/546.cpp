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

inline ll lcm(ll x, ll y)
{
    return x/__gcd(x,y)*y;
}

inline ll f(ll x, ll lim)
{
    return lim/x;
}

int main()
{
    int n;
    ll L,H;
    cin >>n >>L >>H;
    vector<ll> c(n);
    rep(i,n) cin >>c[i];

    ll ans = 0;
    rep(mask,1<<n)
    {
        ll m=1;
        rep(i,n)if(mask>>i&1)
        {
            m = lcm(m,c[i]);
            if(m>H) break;
        }

        int b = __builtin_popcount(mask);
        if(b%2==0) b = -b;
        ans += b*(f(m,H)-f(m,L-1));
    }
    cout << ans << endl;
    return 0;
}
