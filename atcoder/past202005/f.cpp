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

const int A = 26;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    string ans(n, '?');
    rep(i, n) {
        int ni = n - 1 - i;
        if (i > ni) break;

        if (i == ni)
            ans[i] = a[i][0];
        else {
            vector<bool> ex(A);
            rep(j, n) ex[a[i][j] - 'a'] = true;

            char c = '?';
            rep(j, n) {
                if (ex[a[ni][j] - 'a']) {
                    c = a[ni][j];
                    break;
                }
            }

            if (c == '?') {
                cout << "-1\n";
                return 0;
            }
            ans[i] = ans[ni] = c;
        }
    }

    cout << ans << "\n";
    return 0;
}
