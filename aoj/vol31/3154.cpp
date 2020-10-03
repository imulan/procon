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

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

// a^(-1) mod m
// aとmは互いに素でなければならない
ll mod_inverse(ll a, ll m) {
    assert(__gcd(a, m) == 1);
    ll x, y;
    ll g = extgcd(a, m, x, y);
    while (x < 0) x += m;
    return x % m;
}

ll mod_pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) (ret *= x) %= mod;
        n >>= 1;
        (x *= x) %= mod;
    }
    return ret;
}

const int N = 10000000;
int n, m, q;
int d[N];

const int B = 250;
ll v[B][B];
ll b[B];

ll calc(int s, int e) {
    int sb = s / B, eb = e / B;
    ll ret = 1;
    if (s <= e) {
        if (sb == eb) {
            for (int i = s; i <= e; ++i) (ret *= v[sb][i % B]) %= n;
        } else {
            for (int i = s; i < (sb + 1) * B; ++i) (ret *= v[sb][i % B]) %= n;
            for (int i = sb + 1; i < eb; ++i) (ret *= b[i]) %= n;
            for (int i = eb * B; i <= e; ++i) (ret *= v[eb][i % B]) %= n;
        }
    } else {
        for (int i = s; i < (sb + 1) * B; ++i) (ret *= v[sb][i % B]) %= n;
        for (int i = sb + 1; i < B; ++i) (ret *= b[i]) %= n;
        for (int i = 0; i < eb; ++i) (ret *= b[i]) %= n;
        for (int i = eb * B; i <= e; ++i) (ret *= v[eb][i % B]) %= n;
    }
    return ret;
}

int main() {
    rep(i, B) rep(j, B) v[i][j] = 1;

    scanf(" %d %d %d", &n, &m, &q);
    rep(i, m) {
        scanf(" %d", &d[i]);
        v[i / B][i % B] = d[i];
    }

    ll prod_n = 1;
    rep(i, m)(prod_n *= d[i]) %= n;

    rep(i, B) {
        b[i] = 1;
        rep(j, B)(b[i] *= v[i][j]) %= n;
    }

    rep(qi, q) {
        int x, y, z;
        scanf(" %d %d %d", &x, &y, &z);

        --y;

        ll w = mod_pow(prod_n, z / m, n);
        z %= m;
        if (z) (w *= calc(y, (y + z - 1) % m)) %= n;

        // t^w = x (mod n+1)
        // x^r = tとして、 x = x^(r*w) (mod n+1)
        // r*w = 1 (mod n)
        ll r = mod_inverse(w, n);
        ll t = mod_pow(x, r, n + 1);
        printf("%lld\n", t);
    }
    return 0;
}
