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

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

const int mod = 1e9+7;
using mint = ModInt< mod >;
using mm = ModInt<mod-1>;

using vec = vector<mm>;
using mat = vector<vec>;

vec mul(const mat &A, const vec &v){
    int n = A.size();
    vec ret(n);

    rep(i,n){
        rep(j,n) ret[i] += A[i][j]*v[j];
    }
    return ret;
}

mat mul(const mat &A, const mat &B){
    int n = A.size();
    mat C(n, vec(n));

    rep(i,n)rep(j,n){
        rep(k,n) C[i][j] += A[i][k]*B[k][j];
    }
    return C;
}

mat pow(const mat &A, ll x){
    int n = A.size();
    mat M = A;
    mat ret(n,vec(n));
    rep(i,n) ret[i][i] = 1;

    while(x){
        if(x&1) ret = mul(ret, M);
        M = mul(M,M);
        x >>= 1;
    }
    return ret;
}

int main(){
    ll n;
    mint f[4],c;

    cin >>n;
    rep(i,3) cin >>f[i+1];
    cin >>c;

    auto calc = [&](const mat &A, const vec &v){
        mat M = pow(A,n-3);
        vec res = mul(M,v);
        return res[0].x;
    };

    mat A({{1,1,1,2,-6},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}});
    vec v({0,0,0,4,1});
    int W = calc(A,v);

    A = mat({{1,1,1},{1,0,0},{0,1,0}});
    v = vec({0,0,1});
    int X = calc(A,v);
    v = vec({0,1,0});
    int Y = calc(A,v);
    v = vec({1,0,0});
    int Z = calc(A,v);

    cout << c.pow(W)*f[1].pow(X)*f[2].pow(Y)*f[3].pow(Z) << "\n";
    return 0;
}
