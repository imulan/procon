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

ll mod = 1e9+7;

const int N = 4000004;
ll f[N], inv_f[N];

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


inline ll C(int n, int r)
{
    if(n<0 || r<0 || n-r<0) return 0;
    ll ret = f[n];
    (ret*=inv_f[r])%=mod;
    (ret*=inv_f[n-r])%=mod;
    return ret;
}

inline ll H(int n, int r)
{
    if(n==0 && r==0) return 1;
    return C(n+r-1,r);
}

int main()
{
    f[0]=1;
    for(int i=1; i<N; ++i) f[i]=(f[i-1]*i)%mod;

    inv_f[N-1] = mod_inv(f[N-1]);
    for(int i=N-2; i>=0; --i) inv_f[i] = (inv_f[i+1]*(i+1))%mod;

    int a,b,c,sx,sy;
    while(cin >>a >>b >>c >>sx >>sy)
    {
        if(a+b+c+sx+sy==0) break;
        ll ans = 0;
        rep(i,sx+1)
        {
            ll add = 1;
            int j = sy-sx+i;
            (add*=H(a,i-a))%=mod;
            (add*=H(b,j-b))%=mod;
            (add*=H(a+b+c,sx-i))%=mod;

            (ans += add)%=mod;
        }
        (ans*=C(a+b+c,a))%=mod;
        (ans*=C(b+c,b))%=mod;
        printf("%lld\n", ans);
    }
    return 0;
}
