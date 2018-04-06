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

int lcm(int x, int y){
    return x/__gcd(x,y)*y;
}

int euler_phi(int n){
    if(n==0) return 0;
    int ret = n;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            ret -= ret/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) ret -= ret/n;
    return ret;
}

map<int,int> factorize(int n){
    map<int,int> ret;
    for(int i=2; i*i<=n; ++i){
        while(n%i==0){
            n/=i;
            ++ret[i];
        }
    }
    if(n>1) ++ret[n];
    return ret;
}

ll mod_pow(ll x, ll n, ll mod){
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

    map<int,int> f = factorize(n);
    int L = 1;
    for(const auto &p:f){
        if(p.se>1){
            cout << -1 << endl;
            return 0;
        }
        L = lcm(L, p.fi-1);
    }

    if(__gcd(n,L)!=1){
        cout << -1 << endl;
        return 0;
    }

    int ans = L;
    int P = euler_phi(L);
    for(int i=1; i*i<=P; ++i){
        if(P%i==0){
            for(int d:{i,P/i}){
                if(mod_pow(n,d,L) == 1) ans = min(ans,d);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
