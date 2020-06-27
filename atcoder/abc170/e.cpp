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

const int N = 200002;

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    vector<multiset<int>> s(N);
    multiset<int> mx;

    vector<int> a(n), b(n);
    rep(i, n) {
        scanf(" %d %d", &a[i], &b[i]);
        s[b[i]].insert(a[i]);
    }

    rep(i, N) if (!s[i].empty()) mx.insert(*(s[i].rbegin()));

    auto F = [&](int idx, int to) {
        int rate = a[idx];
        int from = b[idx];

        for (int i : {from, to}) {
            if (!s[i].empty()) mx.erase(mx.find(*(s[i].rbegin())));
        }

        s[from].erase(s[from].find(rate));
        s[to].insert(rate);

        for (int i : {from, to}) {
            if (!s[i].empty()) mx.insert(*(s[i].rbegin()));
        }

        b[idx] = to;
        return *(mx.begin());
    };

    rep(i, q) {
        int c, d;
        scanf(" %d %d", &c, &d);
        --c;
        printf("%d\n", F(c, d));
    }
    return 0;
}
