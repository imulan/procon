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
    int k;
    cin >> k;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i <= 9; ++i) pq.push(i);

    ll x;
    rep(loop, k) {
        x = pq.top();
        pq.pop();

        int s = x % 10;
        for (int i = max(0, s - 1); i <= min(9, s + 1); ++i)
            pq.push(x * 10 + i);
    }
    cout << x << '\n';
    return 0;
}
