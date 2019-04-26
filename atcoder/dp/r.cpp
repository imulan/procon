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

const ll mod = 1000000007;

using vec = vector<ll>;
using mat = vector<vec>;

mat mul(const mat &a, const mat &b){
    int n = a.size();
    mat c(n,vec(n));
    rep(i,n)rep(j,n)rep(k,n) (c[i][j] += a[i][k]*b[k][j]) %= mod;
    return c;
}

mat pow(mat a, ll n){
    int A = a.size();
    mat r(A,vec(A));
    rep(i,A) r[i][i] = 1;

    while(n){
        if(n&1) r =  mul(r,a);
        a = mul(a,a);
        n >>= 1;
    }
    return r;
}

int main(){
    int n;
    ll k;
    cin >>n >>k;

    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    mat p = pow(a,k);
    ll ans = 0;
    rep(i,n)rep(j,n) (ans += p[i][j]) %= mod;
    cout << ans << "\n";
    return 0;
}
