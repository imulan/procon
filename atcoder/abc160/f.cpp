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

const int N = 200002;
int n;
vector<int> G[N];

mint f[N], inv_f[N];

int par[N], sz[N];
mint dp[N];
void dfs1(int v, int p) {
    par[v] = p;
    sz[v] = 1;

    for (int c : G[v])
        if (c != p) {
            dfs1(c, v);
            sz[v] += sz[c];
        }

    dp[v] = f[sz[v] - 1];
    for (int c : G[v])
        if (c != p) dp[v] *= dp[c] * inv_f[sz[c]];
}

mint ans[N];
void dfs2(int v, int p, mint pdp) {
    ans[v] = pdp * f[n - 1];

    mint P = pdp;
    mint Q = 1;
    int t = n - 1;
    for (int c : G[v])
        if (c != p) {
            ans[v] *= dp[c] * inv_f[sz[c]];

            P *= dp[c];
            Q *= inv_f[sz[c]];
            t -= sz[c];
        }
    ans[v] *= inv_f[t];
    Q *= inv_f[t];

    // printf(" v %d t %d pdp %d\n", v, t, pdp);

    for (int c : G[v])
        if (c != p) {
            mint nx = P * Q * dp[c].inverse() * f[sz[c]] * f[n - 1 - sz[c]];
            dfs2(c, v, nx);
        }
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i;
    inv_f[N - 1] = f[N - 1].inverse();
    for (int i = N - 2; i >= 0; --i) inv_f[i] = inv_f[i + 1] * (i + 1);

    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs1(0, -1);
    dfs2(0, -1, 1);

    rep(i, n) cout << ans[i] << "\n";
    return 0;
}
