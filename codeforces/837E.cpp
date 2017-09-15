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

map<ll,int> factorize(ll n)
{
    map<ll,int> ret;
    ll t = n;
    for(ll i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            ++ret[i];
            t/=i;
        }
    }
    if(t>1) ++ret[t];

    return ret;
}

ll f(ll a, ll b)
{
    // printf(" CALL: %lld %lld\n", a,b);
    if(b==0) return 0;
    return 1 + f(a, b-__gcd(a,b));
}

int main()
{
    ll x,y;
    cin >>x >>y;
    // cout << f(x,y) << endl;

    ll ans = 0;
    map<ll,int> m = factorize(x);
    ll now = 1;
    while(y>0)
    {
        // printf("y %lld, now %lld, ans %lld\n", y,now,ans);
        ll nx = 0;
        ll times = 1;
        for(const auto &p:m)if(p.se>0)
        {
            ll po = now*p.fi;
            ll tnx = y/po*po;
            if(tnx>nx)
            {
                nx = tnx;
                times = p.fi;
            }
        }
        --m[times];
        ans += (y-nx)/now;
        now *= times;
        y = nx;
    }

    cout << ans << endl;
    return 0;
}
