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

const int INF = 10101010;
const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int N = 1010;
ll f[N];

ll comb(ll n, ll r){
    ll ret = f[n];
    (ret *= mod_inv(f[r])) %= mod;
    (ret *= mod_inv(f[n-r])) %= mod;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int R,C,ai,aj,bi,bj;
    cin >>R >>C >>ai >>aj >>bi >>bj;

    // vertical
    int mi = abs(ai-bi);
    int I = 1;
    for(int ii:{bi+1, R-bi}){
        if(ii < mi){
            mi = ii;
            I = 1;
        }
        else if(ii == mi) ++I;
    }

    // horizontal
    int mj = abs(aj-bj);
    int J = 1;
    for(int jj:{bj+1,C-bj}){
        if(jj < mj){
            mj = jj;
            J = 1;
        }
        else if(jj == mj) ++J;
    }

    cout << mi+mj << " " << (comb(mi+mj,mi)*I*J)%mod << endl;
    return 0;
}
