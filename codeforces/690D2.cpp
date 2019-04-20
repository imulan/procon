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

const ll mod = 1000003;

inline ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

const int N = 750000;
ll f[N];
inline ll C(ll n, ll r)
{
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}


int main()
{
    f[0]=1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int n,c;
    cin >>n >>c;

    ll ans = 0;
    rep(i,n+1) (ans+=C(c-1+i,i))%=mod;
    (ans+=mod-1)%=mod;
    cout << ans << endl;
    return 0;
}
