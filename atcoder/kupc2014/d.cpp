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
const int N = 300000;
ll f[N];

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
    for(int i=1; i<N; ++i) f[i]=(f[i-1]*i)%mod;

    string s[2];
    int d[2];
    rep(i,2) cin >>s[i] >>d[i];

    int n = s[0].size();
    int x = 0;
    rep(i,n) x += (s[0][i]!=s[1][i]);

    ll ans = 0;
    rep(i,x+1)
    {
        int a = d[0]-i, b = d[1]-(x-i);
        if(a>=0 && b>=0 && a==b)
        {
            ll add = (C(x,i)*C(n-x,a))%mod;
            (ans+=add)%=mod;
        }
    }
    cout << ans << endl;
    return 0;
}
