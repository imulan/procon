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

int main() {
    ll n, q;
    cin >> n >> q;

    vector<int> row(n + 1), col(n + 1);
    rep(i, n + 1) row[i] = col[i] = i;

    bool trans = false;

    auto GET = [&](int a, int b) {
        if (trans) swap(a, b);
        return n * (row[a] - 1) + col[b] - 1;
    };

    rep(query, q) {
        int t, a, b;
        cin >> t;
        if (t != 3) cin >> a >> b;

        if (t == 1) {
            if (trans)
                swap(col[a], col[b]);
            else
                swap(row[a], row[b]);
        } else if (t == 2) {
            if (trans)
                swap(row[a], row[b]);
            else
                swap(col[a], col[b]);
        } else if (t == 3)
            trans = !trans;
        else
            cout << GET(a, b) << "\n";
    }

    return 0;
}
