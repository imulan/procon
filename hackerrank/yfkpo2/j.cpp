#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const ll mod = 1e9+7;
using M = map<int,ll>;

int main(){
    int n,m,a,b;
    cin >>n >>m >>a >>b;

    auto IN = [&](int x){
        return 1<=x && x<=m;
    };

    auto calc = [&](int s){
        M dp;
        dp[s] = 1;
        rep(loop,n/2){
            M nx;
            for(const auto &p:dp){
                for(int i=-1; i<=1; ++i){
                    int pos = p.fi+i;
                    if(!IN(pos)) continue;
                    (nx[pos] += p.se) %= mod;
                }
            }
            dp = nx;
        }
        return dp;
    };

    M A=calc(a), B=calc(b);

    M cp;
    ll U = 0;
    ll sub = 0;
    for(const auto &p:A){
        int pos = p.fi;
        if(B.count(pos)){
            ll val = (A[pos]*B[pos])%mod;
            cp[pos] = val;
            (U += val) %= mod;
            (sub += val*val) %= mod;
        }
    }
    U = (U*U)%mod;

    cout << (U-sub+mod)%mod << "\n";
    return 0;
}
