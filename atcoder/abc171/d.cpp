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

const int N = 100010;
ll ct[N];

int main() {
    int n;
    cin >> n;

    ll s = 0;
    rep(i, n) {
        int a;
        cin >> a;
        ++ct[a];
        s += a;
    }

    int q;
    cin >> q;
    while (q--) {
        int b, c;
        cin >> b >> c;

        s += ct[b] * (c - b);
        ct[c] += ct[b];
        ct[b] = 0;

        cout << s << "\n";
    }
    return 0;
}
