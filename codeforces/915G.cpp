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
        if(n&1) (ret*=x) %= mod;
        (x*=x) %= mod;
        n>>=1;
    }
    return ret;
}


const int N = 2000002;
ll pw[N];

bool p[N];
int mu[N];

ll f[N];
vector<int> upd[N];

int main(){
    int n,k;
    cin >>n >>k;

    fill(p,p+N,true);
    fill(mu,mu+N,1);
    p[0] = p[1] = false;
    for(int i=2; i<N; ++i)if(p[i]){
        mu[i] = -1;
        for(int j=2*i; j<N; j+=i){
            p[j] = false;
            mu[j] = -mu[j];
        }

        if((ll)i*i < N){
            for(int j=i*i; j<N; j+=i*i) mu[j] = false;
        }
    }

    rep(i,N) pw[i] = mod_pow(i,n);

    for(int i=1; i<=k; ++i)if(mu[i]!=0){
        for(int j=i; j<=k; j+=i) upd[j].pb(i);
    }

    ll ans = 0;
    ll now = 0;
    for(int i=1; i<=k; ++i){
        for(int j:upd[i]){
            now -= f[j];
            now += mod;

            f[j] = mu[j]*pw[i/j];
            now += f[j];
            now += mod;

            now %= mod;
        }

        ans += now^i;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
