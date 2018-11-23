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

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

int main(){
    int n;
    cin >>n;

    vector<ll> pat(n+1);
    pat[1] = 1;
    for(int i=2; i<=n; ++i){
        pat[i] = (mod_pow(i,10)-mod_pow(i-1,10)+mod)%mod;
    }

    ll ans = 0;
    for(int p=1; p<=n; ++p){
        for(int q=1; q<=n; ++q){
            if(p*q>n) break;
            ans += (pat[p]*pat[q])%mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
    return 0;
}
