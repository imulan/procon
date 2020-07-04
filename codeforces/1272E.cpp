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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto IN = [&](int x) { return 0 <= x && x < n; };

    queue<int> que;
    vector<int> d(n, -1);
    vector<vector<int>> in(n);
    rep(i, n) {
        bool one = false;
        for (int m : {-1, 1}) {
            int j = i + m * a[i];
            if (IN(j)) {
                in[j].pb(i);
                if (a[i] % 2 != a[j] % 2) one = true;
            }
        }
        if (one) {
            d[i] = 1;
            que.push(i);
        }
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i : in[v]) {
            if (d[i] == -1) {
                d[i] = d[v] + 1;
                que.push(i);
            }
        }
    }

    rep(i, n) cout << d[i] << " \n"[i == n - 1];
    return 0;
}
