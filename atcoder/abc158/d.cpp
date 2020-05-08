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
    string s;
    int q;
    cin >> s >> q;

    deque<char> dq;
    for (char c : s) dq.push_back(c);

    int rev = 0;

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1)
            rev ^= 1;
        else {
            int f;
            char c;
            cin >> f >> c;
            --f;
            f ^= rev;

            if (f)
                dq.push_back(c);
            else
                dq.push_front(c);
        }
    }

    vector<char> v(dq.begin(), dq.end());
    if (rev) reverse(all(v));

    for (char c : v) cout << c;
    cout << "\n";
    return 0;
}
