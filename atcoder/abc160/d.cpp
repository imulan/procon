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
    int n, x, y;
    cin >> n >> x >> y;
    --x;
    --y;

    vector<int> a(n + 1);
    int c = y - x + 1;

    auto ADD_C = [&](int d) {
        ++a[d];
        --a[d + 1];
        a[d + 1] += 2;
        a[d + (c + 1) / 2] -= 2;
        if (c % 2 == 0) {
            ++a[d + c / 2];
            --a[d + c / 2 + 1];
        }
    };

    rep(i, x) {
        // cycle
        ADD_C(x - i);

        // i->0
        ++a[1];
        --a[i + 1];

        // i->x-1
        ++a[1];
        --a[x - 1 - i + 1];

        // y+1->n-1
        if (y < n - 1) {
            int w = n - 1 - y;
            int s = x - i + 2;
            ++a[s];
            --a[s + w];
        }
    }

    for (int i = x; i <= y; ++i) {
        // cycle
        ADD_C(0);

        // x-1->0
        if (x > 0) {
            int w = x;
            int s = min(i - x, y - i + 1) + 1;
            ++a[s];
            --a[s + w];
        }
        // y+1->n-1
        if (y < n - 1) {
            int w = n - 1 - y;
            int s = min(i - x + 1, y - i) + 1;
            ++a[s];
            --a[s + w];
        }
    }

    for (int i = y + 1; i < n; ++i) {
        // cycle
        ADD_C(i - y);

        // i->n-1
        ++a[1];
        --a[n - 1 - i + 1];

        // i->y+1
        ++a[1];
        --a[i - (y + 1) + 1];

        // x-1->0
        if (x > 0) {
            int w = x;
            int s = i - y + 2;
            ++a[s];
            --a[s + w];
        }
    }

    rep(i, n) a[i + 1] += a[i];
    for (int i = 1; i < n; ++i) cout << a[i] / 2 << "\n";
    return 0;
}
