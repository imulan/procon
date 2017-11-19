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

const ll mod = 1e9+7;

inline ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n>0)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x, mod-2);
}

const int N = 300030;
ll f[N];

inline ll C(ll n, ll r)
{
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}

ll calc(string s, int k)
{
    int n = s.size();

    int x=0, y=0;
    rep(i,n/2)
    {
        if(s[i]==s[n-1-i]) ++y;
        else ++x;
    }

    vector<ll> yy(y+1);
    yy[0] = 1;
    for(int i=1; i<=y; ++i) yy[i] = (yy[i-1] + (C(y,i)*mod_pow(25,i))%mod)%mod;

    ll ret = 0;
    rep(p,x+1)
    {
        int cost = x+p;
        if(cost>k) break;

        ll add = C(x,p);
        (add*=mod_pow(24,p))%=mod;
        (add*=mod_pow(2,x-p))%=mod;

        int rem = (k-cost)/2;
        (add*=yy[min(y,rem)])%=mod;

        (ret+=add)%=mod;
    }

    // printf(" k %d: %lld\n", k,ret);
    return ret;
}

ll solve()
{
    int n,k;
    string s;
    cin >>n >>k >>s;

    ll ret = calc(s,k);
    if(n%2==1) (ret += 25*calc(s,k-1)) %= mod;
    return ret;
}

int main()
{
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
