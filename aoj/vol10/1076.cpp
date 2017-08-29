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

const ll INF = 2000000001;

ll lcm(ll x, ll y)
{
    ll ret = x/__gcd(x,y)*y;
    return min(INF,ret);
}

ll s(ll a, ll n)
{
    return n*(n+1)/2*a;
}

double solve(ll n, int m)
{
    vector<ll> p(m);
    rep(i,m) cin >>p[i];

    ll num = 0;
    rep(mask,1<<m)
    {
        ll L = 1;
        rep(i,m)if(mask>>i&1) L = lcm(L,p[i]);

        ll x = n/L;
        if(__builtin_popcount(mask)%2==1) num-=x;
        else num+=x;
    }

    if(num==0) return 0;

    double d = num;
    double ret = 0;
    rep(mask,1<<m)
    {
        ll L = 1;
        rep(i,m)if(mask>>i&1) L = lcm(L,p[i]);

        if(L>n) continue;

        ll x = n/L;
        if(__builtin_popcount(mask)%2==1) ret -= s(L,x)/d;
        else ret += s(L,x)/d;
    }

    return ret;
}

int main()
{
    int n,m;
    while(cin >>n >>m,n) printf("%.10f\n", solve(n,m));
    return 0;
}
