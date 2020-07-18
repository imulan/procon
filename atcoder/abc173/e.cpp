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

using D = long double;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p, m;
    int zero = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a == 0)
            ++zero;
        else if (a > 0)
            p.pb(a);
        else
            m.pb(-a);
    }
    sort(all(p));
    sort(all(m));

    int P = p.size(), M = m.size();

    vector<D> pls(P + 1), mls(M + 1);
    vector<mint> pp(P + 1), mp(M + 1);
    auto MAKE = [&]() {
        pls[0] = 0;
        pp[0] = 1;
        rep(i, P) {
            pls[i + 1] = log((D)p[i]) + pls[i];
            pp[i + 1] = pp[i] * p[i];
        }

        mls[0] = 0;
        mp[0] = 1;
        rep(i, M) {
            mls[i + 1] = log((D)m[i]) + mls[i];
            mp[i + 1] = mp[i] * m[i];
        }
    };
    D mx = -1;
    mint ans;

    // positive
    reverse(all(p));
    reverse(all(m));
    MAKE();
    for (int i = 0; i <= M; i += 2) {
        int j = k - i;
        if (j < 0 || P < j) continue;

        D t = mls[i] + pls[j];
        if (mx < t) {
            mx = t;
            ans = mp[i] * pp[j];
        }
    }

    if (mx > -0.1) {
        cout << ans << "\n";
        return 0;
    }

    // zero
    if (zero) {
        cout << 0 << "\n";
        return 0;
    }

    // negative
    reverse(all(p));
    reverse(all(m));
    MAKE();

    D mn = 1e9;
    for (int i = 1; i <= M; i += 2) {
        int j = k - i;
        if (j < 0 || P < j) continue;

        D t = mls[i] + pls[j];
        if (t < mn) {
            mn = t;
            ans = mp[i] * pp[j];
        }
    }
    cout << -ans << "\n";
    return 0;
}
