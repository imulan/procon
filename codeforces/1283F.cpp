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
    int n;
    cin >> n;

    vector<int> ct(n);
    vector<int> a(n - 1);
    rep(i, n - 1) {
        cin >> a[i];
        --a[i];
        ++ct[a[i]];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, n) if (ct[i] == 0) pq.push(i);

    vector<pair<int, int>> e;
    for (int i = n - 2; i >= 0; --i) {
        if (pq.empty()) {
            cout << -1 << "\n";
            return 0;
        }

        int v = pq.top();
        pq.pop();
        int u = a[i];
        e.pb({u, v});
        --ct[u];
        if (ct[u] == 0) pq.push(u);
    }

    int root = pq.top();
    cout << root + 1 << "\n";
    for (const auto& p : e) cout << p.fi + 1 << " " << p.se + 1 << "\n";
    return 0;
}
