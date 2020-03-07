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

const int mod = 1e6+3;
using mint = ModInt< mod >;

int ASK(int x){
    cout << "? " << x << endl;
    int ret;
    cin >>ret;
    return ret;
}

void OUT(int x){
    cout << "! " << x << endl;
}

const int k = 10;
const int N = 15;
mint f[N];

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = f[i-1]*i;

    vector<mint> Y(k+1);
    rep(i,k+1) Y[i] = ASK(i);

    vector<mint> qq(k+1);
    rep(i,k+1){
        mint q = f[i]*f[k-i];
        if((k-i)%2 == 1) q = -q;
        qq[i] = Y[i]/q;
    }

    auto F = [&](int x){
        if(x < k+1) return Y[x];

        mint P = 1;
        rep(i,k+1) P *= x-i;

        mint ret = 0;
        rep(i,k+1) ret += P/(x-i)*qq[i];
        return ret;
    };

    rep(i,mod){
        if(F(i) == 0){
            OUT(i);
            return 0;
        }
    }

    OUT(-1);
    return 0;
}
