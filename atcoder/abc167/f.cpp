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

using pi = pair<int, int>;

string rev(const string& s) {
    string t = s;
    reverse(all(t));
    rep(i, t.size()) {
        if (t[i] == '(')
            t[i] = ')';
        else
            t[i] = '(';
    }
    return t;
}

pi F(const string& s) {
    int ct = 0, mn = 0;
    for (char c : s) {
        if (c == '(')
            ++ct;
        else
            --ct;
        mn = min(mn, ct);
    }
    return {mn, ct};
}

int check(vector<pi> v) {
    sort(all(v), greater<pi>());

    int V = v.size();
    int vi = 0, now = 0;
    priority_queue<int> pq;

    rep(loop, V) {
        while (vi < V && v[vi].fi + now >= 0) {
            pq.push(v[vi].se);
            ++vi;
        }
        if (pq.empty()) return -1;
        now += pq.top();
        pq.pop();
    }
    return now;
}

int main() {
    int n;
    cin >> n;

    vector<pi> L, R;
    rep(i, n) {
        string s;
        cin >> s;

        int ct = 0;
        for (char c : s) {
            if (c == '(')
                ++ct;
            else
                --ct;
        }

        if (ct >= 0)
            L.pb(F(s));
        else
            R.pb(F(rev(s)));
    }

    int l = check(L), r = check(R);

    string ans = "Yes";
    if (l == -1 || r == -1 || l != r) ans = "No";
    cout << ans << "\n";
    return 0;
}
