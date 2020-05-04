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

const int B = 101;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> task(n + 1);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        task[a].pb(b);
    }

    priority_queue<int> pq;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j : task[i]) pq.push(j);
        ans += pq.top();
        pq.pop();

        cout << ans << "\n";
    }
    return 0;
}
