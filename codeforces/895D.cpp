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

const int A = 26;
const int N = 1000001;
const ll mod = 1e9+7;

ll f[N];
ll inv_f[N];

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

ll calc(const string &s, const vector<int> &CT){
    vector<int> ct(CT);
    int n = s.size();

    ll ret = 0;
    rep(i,n){
        int U = n-i;
        ll base = f[U];
        rep(j,A) (base *= inv_f[ct[j]]) %= mod;
        (base *= mod_inv(U)) %= mod;

        rep(j,s[i]-'a'){
            ll add = base;
            (add *= ct[j]) %= mod;
            (ret += add) %= mod;
        }

        // 同じ文字を選んで次のステップへ
        if(ct[s[i]-'a']==0) break;
        --ct[s[i]-'a'];
    }
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
    inv_f[N-1] = mod_inv(f[N-1]);
    for(int i=N-2; i>=0; --i) inv_f[i] = (inv_f[i+1]*(i+1))%mod;

    string a,b;
    cin >>a >>b;

    vector<int> ct(A);
    rep(i,a.size()) ++ct[a[i]-'a'];

    cout << (calc(b,ct)-calc(a,ct)-1+2*mod)%mod << endl;
    return 0;
}
