// clang-format off
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
// clang-format on

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
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
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
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
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

const int mod = 1e9 + 7;
using mint = ModInt<mod>;

// for test
// 200560490130
// 963761198400

const int N = 7000;
mint fact[N], inv_fact[N];
mint C(int n, int r) {
    if (n < r) return 0;
    return fact[n] * inv_fact[r] * inv_fact[n - r];
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i;
    inv_fact[N - 1] = fact[N - 1].inverse();
    for (int i = N - 2; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1);

    ll n;
    cin >> n;

    map<ll, int> f;
    vector<ll> d({1, n});

    ll t = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            d.pb(i);
            d.pb(n / i);
        }
        while (t % i == 0) {
            ++f[i];
            t /= i;
        }
    }
    if (t > 1) ++f[t];
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    int D = d.size();

    int F = f.size();
    vector<ll> x;
    vector<int> num;
    for (const auto &p : f) {
        x.pb(p.fi);
        num.pb(p.se);
    }

    vector<int> cand(1 << F);
    rep(i, D) {
        int cv = 0;
        ll xx = d[i];
        rep(j, F) {
            int ct = 0;
            while (xx % x[j] == 0) {
                ++ct;
                xx /= x[j];
            }
            if (ct == num[j]) cv |= (1 << j);
        }
        ++cand[cv];
    }
    rep(i, F) {
        rep(mask, 1 << F) {
            if (mask & (1 << i)) cand[mask] += cand[mask ^ (1 << i)];
        }
    }

    mint ans = 0;
    for (int i = 1; i <= D; ++i) {
        mint pat = 0;
        rep(mask, 1 << F) {
            int mul = 1;
            if ((F - __builtin_popcount(mask)) % 2) mul = -1;
            pat += C(cand[mask], i) * mul;
        }
        ans += pat * fact[i];
    }
    cout << ans << "\n";
    return 0;
}
