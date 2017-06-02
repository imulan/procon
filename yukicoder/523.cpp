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

ll mod_pow(ll x, ll n)
{
    ll pw[32]={};
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,32)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

int main()
{
    ll n;
    cin >>n;

    ll ans=1;
    for(int i=2; i<=2*n; ++i) (ans*=i)%=mod;

    rep(i,n) (ans*=mod_inv(2))%=mod;
    cout << ans << endl;
    return 0;
}
