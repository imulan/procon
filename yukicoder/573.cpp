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
    ll r = 1;
    while(n)
    {
        if(n&1) (r*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return r;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

const int N=100010;
ll f[N];
inline ll C(int n, int k)
{
    ll r = f[n];
    (r*=mod_inv(f[k]))%=mod;
    (r*=mod_inv(f[n-k]))%=mod;
    return r;
}

int main()
{
    f[0]=1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int n;
    cin >>n;

    ll ans = 0;
    rep(i,n+1)
    {
        ll add = C(n,i);
        (add*=mod_pow(i,n-i))%=mod;
        (ans+=add)%=mod;
    }

    cout << ans << endl;
    return 0;
}
