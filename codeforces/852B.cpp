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

using vl = vector<ll>;
using mat = vector<vl>;

mat mul(const mat &A, const mat &B){
    int n = A.size();
    mat C(n,vl(n));
    rep(i,n)rep(j,n)rep(k,n) (C[i][j] += A[i][k]*B[k][j]) %= mod;
    return C;
}

mat mat_pow(const mat &A, int x){
    int n = A.size();

    mat a(A);
    mat P(n,vl(n));
    rep(i,n) P[i][i]=1;
    while(x){
        if(x&1) P = mul(P,a);
        a = mul(a,a);
        x >>= 1;
    }
    return P;
}

vl mul(const mat &A, const vl &b){
    int n = A.size();
    vl ret(n);
    rep(i,n)rep(j,n) (ret[i] += A[i][j]*b[j]) %= mod;
    return ret;
}

int main(){
    int n,l,m;
    scanf(" %d %d %d", &n, &l, &m);

    vector<int> s(n),h(n),t(n);
    rep(i,n){
        scanf(" %d", &s[i]);
        s[i] %= m;
    }
    rep(i,n){
        scanf(" %d", &h[i]);
        h[i] %= m;
    }
    rep(i,n){
        scanf(" %d", &t[i]);
        t[i] %= m;
    }

    vl b(m);
    rep(i,n) ++b[s[i]];
    // dbg(b);

    mat P(m,vl(m));
    rep(i,n){
        rep(j,m){
            ++P[(j+h[i])%m][j];
        }
    }

    mat Q = mat_pow(P,l-2);

    vl res = mul(Q,b);
    // dbg(res);
    ll ans = 0;
    rep(i,n){
        int cost = (t[i]+h[i])%m;
        cost = (m-cost)%m;
        // dbg(cost);
        (ans += res[cost]) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
