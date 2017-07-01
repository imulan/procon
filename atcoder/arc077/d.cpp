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

const int N = 222222;
ll fact[N];

inline ll mod_pow(ll x, ll n)
{
    ll r=1;
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
    if(n-r<0) return 0;

    ll ret = fact[n];
    (ret*=mod_inv(fact[r]))%=mod;
    (ret*=mod_inv(fact[n-r]))%=mod;
    return ret;
}

int main()
{
    fact[0]=1;
    for(int i=1; i<N; ++i) fact[i]=(fact[i-1]*i)%mod;

    int n;
    cin >>n;
    vector<int> a(n+1);
    rep(i,n+1) cin >>a[i];

    vector<int> ct(n+1);
    rep(i,n+1) ++ct[a[i]];

    int x = -1;
    for(int i=1; i<=n; ++i)if(ct[i]==2) x=i;

    int f = -1, s = -1;
    rep(i,n+1)
    {
        if(a[i] == x)
        {
            if(f==-1) f=i;
            else s=i;
        }
    }

    printf("%d\n", n);
    for(int i=2; i<=n; ++i)
    {
        ll ans = 0;

        (ans+=C(n+1-2,i))%=mod;
        (ans+=C(n+1-2,i-1)*2)%=mod;

        int rem = f+(n-s);
        if(rem>=i-1)
        {
            // printf(" !!! %d , rem %d\n", i, rem);
            ans = (ans+mod-C(rem,i-1))%mod;
        }
        (ans+=C(n+1-2,i-2))%=mod;

        // printf("-------- i %d, naswer     is---\n", i);
        printf("%lld\n", ans);
    }
    printf("1\n");
    return 0;
}
