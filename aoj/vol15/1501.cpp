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

const ll mod = 1e8+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int N = 2020;
ll f[N];
ll C(ll n, ll r){
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}

int main(){
    f[0]=1;
    for(ll i=1; i<N; ++i) f[i]=(f[i-1]*i)%mod;

    int r,c,a1,a2,b1,b2;
    cin >>r >>c >>a1 >>a2 >>b1 >>b2;

    int mul = 1;
    int X = abs(a1-b1);
    if(X == r-X) mul *= 2;
    X = min(X,r-X);

    int Y = abs(a2-b2);
    if(Y == c-Y) mul *= 2;
    Y = min(Y,c-Y);

    cout << (C(X+Y,X)*mul)%mod << endl;
    return 0;
}
